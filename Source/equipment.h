#ifndef __EQUIPMENT_H_
#define __EQUIPMENT_H_

namespace Harley{
    class Equipment{
      public:
        enum Slot {Helmet, Chestplate, Leggings, Boots};
        Slot slot();
        int defence();
        int weight();
        int resistance();
        int hp();
        int stamina();
        int attack();
        std::string description();
        std::string name();
        Equipment(Slot, std::string, std::string, int, int, int=0, int=0, int=0, int=0);
      private:
        Slot slot;
        int defence;
        int weight;
        int resistance;
        int hp;
        int stamina;
        int attack;
        std::string description;
        std::string name;
    }
}

// Leather Armor
#define Equipment::LeatherHat (Equipment::Helmet, "Leather Hat", "Its comfy, but not all that protective", 1, 5)
#define Equipment::LeatherArmor (Equipment::Chestplate, "Leather Armor", "It would appear that combining wood and leather creates something more protective than wood!", 2, )
#define Equipment::LeatherPants (Equipment::Leggings, "Leather Pants", "Skintight", 2, 15)
#define Equipment::LeatherBoots (Equipment::Boots, "Leather Boots", "They Look alright"")

// Wooden Armor
#define

#endif // __EQUIPMENT_H_
