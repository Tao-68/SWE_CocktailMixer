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

    // Löscht den momentanen Rezeptschritt und setzt den Namen
    Recipe(void);

    ~Recipe();

    // Gibt Anzahl der Rezeptschritte aus
    int getNoOfRecipeSteps();

    /* Gibt einen Pointer auf den momentanen Rezeptschritt aus,
     * sofern er nicht größer als die maximalen Schritte ist.
     */
    RecipeStep * getRecipeStep(unsigned int i);

    // Gibt Rezeptnamen zurück
    std::string getName(void) const;

    // Setzt Rezeptnamen
    void setName(const std::string& Name);

    /* Fügt dem Rezept einen weiteren Schritt hinzu.
     * Der Schritt beinhaltet eine gebrauchte Zutat und dessen Menge.
     * Der Schritt wird dann der Liste "m_RecipeStep" hinzugefügt
     */
    void appendStep(std::string z, float m);

    // Gibt alle Zutaten aus, die für die einzelnen Schritte des aufrufenden Rezeptes gebraucht werden
    void browse();

};

#endif
