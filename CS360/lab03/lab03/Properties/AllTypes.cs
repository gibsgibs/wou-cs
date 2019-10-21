using System;
using System.Collections.Generic;
using System.Text;

namespace lab03
{
    public interface AllTypes
    {
        public static List<string> aTypes = new List<string>(new string[] { "Dark", "Earth", "Fire", "Light", "Water", "Wind" });
        public static List<string> cTypes = new List<string>(new string[] { "Monster", "Spell", "Trap" });
        public static List<string> mTypes = new List<string>(new string[] { "Aqua", "Beast", "Beast-Warrior", "Cyberse", "Dinosaur", "Dragon", "Fairy", "Fiend", "Fish", "Insect",
                                                                     "Machine", "Plant", "Pyro", "Reptile","Rock", "Sea Serpent", "Spellcaster", "Thunder", "Warrior",
                                                                     "Winged Beast", "Wyrm", "Zombie"});
    }
}
