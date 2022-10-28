#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <list>
#include <string>

class Recipe {
private:
    std::list<RecipeStep*> m_RecipeStep;

    std::string m_Name;

public:

    Recipe(void);

    ~Recipe();

    int getNoOfRecipeSteps();

    RecipeStep * getRecipeStep(unsigned int i);

    std::string getName(void) const;

    void setName(const std::string& Name);

    void appendStep(std::string z, float m);

    void browse();

};

#endif
