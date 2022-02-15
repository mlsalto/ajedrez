
#define USE_ETSIDI
#pragma comment(lib,"ETSIDI.lib")
//Cabecera Publica de ETSIDI. GENERADA AUTOMATICAMENTE
//#ifdef _DEBUG
//#pragma comment(lib,"lib/ETSIDI_d.lib")
//#else
//#pragma comment(lib,"lib/ETSIDI.lib")
//#endif

/****************************************************************************
ETSIDIlib - 2016

DESCRIPTION: It is a simple wrapper of several libs and utilities, some of then 
	written by me, but others are free of use for non-comercial purposes libraries
	or pieces of software. Thus, for ttf, the freetype lib is being used, and for 
	sound issues, FMod_ex lib is used. The PNG codification is decoded through 
	lodePNG "lib" (is just a simple cpp file). I've made caches and singletons, 
	trying to make a very, very, simple interface for my students. They are working 
	on Visual Studio so the binaries are only included for that IDE. Anyway, it is 
	quite easy to adapt the code to any other platform due to the use of multiplatform
	libs. 

AUTHOR: Miguel Hernando
		Universidad Politecnica de Madrid
****************************************************************************/

#pragma once
#include <windows.h>
#include <GL/gl.h>              /* Header File For The OpenGL Library */
#include <GL/glu.h>
#include <cmath>


#ifndef USE_ETSIDI
#define ETSIDI_API __declspec(dllexport) 
#else
#define ETSIDI_API __declspec(dllimport) 
#endif

namespace ETSIDI
{
using namespace std;
	//CLASES PUBLICAS---------------------------------------------
	struct GLTexture {
		GLuint id;
		int width;
		int height;
	};
	//CONSTANTES Y ENUMERACIONES----------------------------------
	enum JUSTIFICACION_H{
		IZQUIERDA,
		ORIGEN,
		DERECHA,
		CENTRO
	};
	enum JUSTIFICACION_V{
		INFERIOR,
		LINEA_BASE,
		MEDIO,
		SUPERIOR
	};
//funciones globales publicas 
	//FUNCIONES PARA LEER TEXTURAS--------------------------------
	ETSIDI_API GLTexture getTexture(const char * texturePath);
	//FUNCIONES PARA GENERAR NUMEROS ALEATORIOS-------------------
	ETSIDI_API double lanzaDado(double max=1.0, double min=0.0F);
	ETSIDI_API int lanzaDado(int max, int min=1);
	ETSIDI_API bool lanzaMoneda();
	//FUNCIONES PARA MEDIR EL TIEMPO------------------------------
	ETSIDI_API long getMillis();
	//FUNCIONES PARA IMPRIMIR UN TEXTO EN OPENGL CON FUENTES TTF--
	ETSIDI_API void setJustificacion(JUSTIFICACION_H just=IZQUIERDA, JUSTIFICACION_V=LINEA_BASE);
	ETSIDI_API void setTextColor(float r, float g, float b, float alpha=1.0F);
	ETSIDI_API void setFont(const char *fuente, int size=12);
	ETSIDI_API void print( const char *txt, const char *fuente=0, int size=12); 
	ETSIDI_API void printxy(const char *txt, int x, int y, int z=0);
	//FUNCIONES PARA REPRODUCIR SONIDOS Y MUSICA------------------
	ETSIDI_API void play(const char *  soundPath);
	ETSIDI_API void playMusica(const char *  soundPath, bool repite=false);
	ETSIDI_API void stopMusica();
	//CLASES UTILES-----------------------------------------------
	class Vector2D  {
	public: 
		double x;
		double y;
	public: 
		Vector2D(double xv=0.0f,double yv=0.0f):x(xv),y(yv){} 
		Vector2D operator - (const Vector2D v)const {return Vector2D(x-v.x,y-v.y);}   
		Vector2D operator + (const Vector2D v)const {return Vector2D(x+v.x,y+v.y);}    
		double operator *(const Vector2D v)const  {return x*v.x+y*v.y;}       
		Vector2D operator *(double d)const {return Vector2D(x*d,y*d);}    
		double module(){return (double)sqrt(x*x+y*y);}              
		double argument(){return (double)atan2(y,x);}          
		Vector2D unit(){ Vector2D ret(x,y);
			double mod=module();
			if(mod>0.00001)ret=ret*(1/mod);
			return ret;
		}         
    
	};
	//CLASE SPRITE------------------------------------------------------------
	//un rectangulo con textura que facilita el dibujo y animación en pantalla
	class Sprite
	{
	public:
		ETSIDI_API Sprite(const char *texturePath, float x=0, float y=0, float width=-1, float height=-1);
		ETSIDI_API virtual ~Sprite();
		ETSIDI_API virtual void draw();
		ETSIDI_API virtual void loop();
		void setPos(float x, float y);
		void setVel(float vx, float vy);
		void setSize(float w, float h);
		void setCenter(float cx, float cy); 
		void flip(bool h,bool v);
		bool isFlippedH() const;
		bool isFlippedV() const;
		void setAngle(double angle);
		double getAngle() const; 
		ETSIDI_API bool collides(const Sprite &s) const;
	
	protected:
		ETSIDI_API double tick();
		long int last_update;
		GLTexture _texture;
		double _angle; //sprite rotation
		Vector2D pos;
		Vector2D vel; //pixels per second
		float _width;
		float _height;
		Vector2D anchor;
		bool horizontal_flip;
		bool vertical_flip;
		char _texturePath[255];
	};
	//CLASE SPRITESEQUENCE------------------------------------------------------------
	//un sprite con una secuencia de imagenes que hacen una animación.
	class SpriteSequence: public Sprite
	{
	public:
		ETSIDI_API SpriteSequence(const char *texturePath, int cols, int rows=1, int ms_step = 50, bool repeat = true, float x=0, float y=0, float w=-1.0F, float h=-1.0F, int initState=0);
		ETSIDI_API ~SpriteSequence();
		ETSIDI_API virtual void draw();
		ETSIDI_API virtual void loop();
		ETSIDI_API void setState(int index, bool pause=true);
		ETSIDI_API int getState();
		ETSIDI_API void pause(bool stop=true){_pause=stop;}
	
	protected:
		int _cols, _rows;
		long int initial_time;
		int _ms_step;
		bool _pause;
		int state;
		bool _repeat;
	};







	//-----------------------------------------------------------------------------------------------


	//metodos inline SPRITE 
	inline void Sprite::setAngle(double angle){
			if(angle+180>360)angle-=360.0*((int)((angle+180)/360));
			if(angle-180<-360)angle-=360.0*((int)((angle-180)/360));
			_angle=angle;
	}
	inline void Sprite::setSize(float w, float h)
	{
			if(w<0)w = (float)_texture.width;
			if(h<0)h = (float)_texture.height;
			_width = w;
			_height = h;
	}
	inline double Sprite::getAngle() const {return _angle;}
	inline void Sprite::setPos(float x, float y){pos.x=x;pos.y=y;}
	inline void Sprite::setCenter(float cx, float cy){anchor.x=cx; anchor.y=cy;} 
	inline void Sprite::flip(bool h,bool v){horizontal_flip=h; vertical_flip=v;}
	inline bool Sprite::isFlippedH() const{return horizontal_flip;}
	inline bool Sprite::isFlippedV() const{return vertical_flip;}
}//ETSIDI