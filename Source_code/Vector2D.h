#ifndef _Vector2D_h_
#define _Vector2D_h_

#include <math.h>

using namespace std;

class Vector2D
{
public:
    Vector2D(double x = 0, double y = 0) : m_x(x), m_y(y) {};
    virtual ~ Vector2D(){}
    double getX() { return m_x; }
    double getY() { return m_y; }

    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }

    double length() { return sqrt(m_x * m_x + m_y * m_y); }

    Vector2D operator + ( const Vector2D& v2 ) const ;
    Vector2D &operator += ( const Vector2D& v2 ) ;

    Vector2D operator * ( double pow_up ) ;
    Vector2D& operator *= ( double pow_up );

    Vector2D operator - ( const Vector2D& v2 ) const ;
    Vector2D &operator -= ( const Vector2D& v2 ) ;

    Vector2D operator / ( double div_down ) ;
    Vector2D& operator /= ( double div_down );

    bool operator == (const Vector2D& v2) const;

    void normalize() ;

    Vector2D& operator = ( const Vector2D& v2 );
private:
    double m_x, m_y;
};

#endif // _Vector2D_h_
