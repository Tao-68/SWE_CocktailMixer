#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

class RecipeStep {
 private:
    std::string m_Zutat;

    float m_Menge;

 public:

    RecipeStep(void);

    ~RecipeStep();

    std::string getZutat(void) const;

    float getMenge(void) const;

    void setZutat(std::string m_Zutat);

    void setMenge(float m_Menge);

};
#endif
