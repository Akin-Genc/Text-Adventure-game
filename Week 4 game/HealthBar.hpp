#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include <string>

class HealthBar {
private:
    int health;

public:
    HealthBar(int initialHealth);
    std::string GetHealthBar() const;
    std::string EGetHealthBar() const;
    void SetHealth(int newHealth);
    void ESetHealth(int newHealth);
};

#endif

 