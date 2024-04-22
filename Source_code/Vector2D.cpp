#include "Vector2D.h"

using namespace std;

// +
Vector2D Vector2D ::
operator + ( const Vector2D& v2 ) const
{
    return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D& Vector2D ::
operator += ( const Vector2D& v2 )
{
    m_x += v2.m_x;
    m_y += v2.m_y;
    return *this;
}

// -
Vector2D Vector2D ::
operator - ( const Vector2D& v2 ) const
{
    return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D& Vector2D ::
operator -= ( const Vector2D& v2 )
{
    m_x -= v2.m_x;
    m_y -= v2.m_y;
    return *this;
}

//*
Vector2D Vector2D::
operator * ( double pow_up )
{
    return Vector2D(m_x * pow_up, m_y * pow_up);
}

Vector2D& Vector2D ::
operator = ( const Vector2D& v2 )
{
    m_x = v2.m_x;
    m_y = v2.m_y;
    return *this;
}

Vector2D& Vector2D ::
operator *= ( double pow_up )
{
    m_x *= pow_up;
    m_y *= pow_up;
    return *this;
}

// /
Vector2D Vector2D ::
operator / ( double div_down )
{
    return Vector2D(m_x / div_down, m_y / div_down);
}

Vector2D& Vector2D ::
operator /= ( double div_down )
{
    m_x /= div_down;
    m_y /= div_down;
    return *this;
}

void Vector2D :: normalize()
{
    double l = length();
    if (l > 0)  (*this) *= 1 / l;
}

bool Vector2D ::
operator == ( const Vector2D& v2 ) const
{
    return m_x ==  v2.m_x && m_y == v2.m_y;
}
