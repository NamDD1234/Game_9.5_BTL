#pragma once

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int>ii;
typedef pair<int, ii>iii;
class Specification
{
public:
    Specification(double max_numammo,
                  double gun_recoil,
                  double time_reload,
                  double fire_speed,
                  iii dame_15m,
                  iii dame_30m,
                  iii dame_50m,
                  bool autofire) :
                      m_max_numammo(max_numammo),
                      m_gun_recoil(gun_recoil),
                      m_time_reload(time_reload),
                      m_fire_speed(fire_speed),
                      m_dame_15m(dame_15m),
                      m_dame_30m(dame_30m),
                      m_dame_50m(dame_50m),
                      m_autofire(autofire){}
    ~Specification(){};
    double get_maxammo() { return m_max_numammo; }
    double get_recoil() { return m_gun_recoil; }
    double get_timereload() { return m_time_reload; }
    double get_firespeed() { return m_fire_speed; };
    iii get_15() { return m_dame_15m; }
    iii get_30() { return m_dame_30m; }
    iii get_50() { return m_dame_50m; }
    bool get_autofire() { return m_autofire; }

private:
    double m_max_numammo;

    double m_gun_recoil;

    double m_time_reload;

    double m_fire_speed;
    iii m_dame_15m, m_dame_30m, m_dame_50m;
    bool m_autofire;

};
