using System;
using System.Collections.Generic;

namespace lab03
{
    /// <summary>
    /// This entire "class" is my sudo-database. Due to a lack of knowledge in SQL and MySQL, this class is filling in for what would be
    /// and actual database. It is simply a list of card names, and then a dictionary to map each card name to the elements of that card.
    /// For example, if the name of the card is "Mejesty's Fiend" then it is a monster card, so the nameCardTypePairs dictionary will map that
    /// name to the card type "Monster". This same procedure is done for all the cards in the list of card names. 
    /// Is this the most effective way to get the desired outcome? No! But it works.
    /// </summary>
    public static class MyGlobals
    {
        public static List<string> allNames = new List<string>()
        {
            {"Blue-Eyes White Dragon"},
            {"Dark Magician"},
            {"Harpie's Feather Duster"},
            {"Compulsory Evacuation Device"},
            {"Polymerization"},
            {"Tellarknight Genesis"},
            {"Infected Mail"},
            {"Gladiator Beast War Chariot"},
            {"Armageddon Knight"},
            {"Majesty's Fiend"},
            {"Vanity's Emptiness"}
        };
        
        public static Dictionary<string, string> nameCardTypePairs = new Dictionary<string, string>()
        {
            {"Blue-Eyes White Dragon", "Monster"},
            {"Dark Magician", "Monster"},
            {"Harpie's Feather Duster", "Spell"},
            {"Compulsory Evacuation Device","Trap"},
            {"Polymerization", "Spell"},
            {"Tellarknight Genesis", "Spell"},
            {"Infected Mail", "Spell"},
            {"Gladiator Beast War Chariot", "Trap"},
            {"Armageddon Knight", "Monster"},
            {"Majesty's Fiend", "Monster"},
            {"Vanity's Emptiness", "Trap"}
        };

        public static Dictionary<string, string> nameAttributePairs = new Dictionary<string, string>()
        {
            {"Blue-Eyes White Dragon", "Light"},
            {"Dark Magician", "Dark" },
            {"Armageddon Knight", "Dark"},
            {"Majesty's Fiend", "Light"}
        };

        public static Dictionary<string, int> nameLevelPairs = new Dictionary<string, int>()
        {
            {"Blue-Eyes White Dragon", 8},
            {"Dark Magician", 7},
            {"Armageddon Knight", 4},
            {"Majesty's Fiend", 6}
        };

        public static Dictionary<string, string> nameRacePairs = new Dictionary<string, string>()
        {
            {"Blue-Eyes White Dragon", "Dragon"},
            {"Dark Magician", "Spellcaster"},
            {"Armageddon Knight", "Warrior"},
            {"Majesty's Fiend", "Fiend"}
        };

        public static Dictionary<string, string> nameMonsterTypePairs = new Dictionary<string, string>()
        {
            {"Blue-Eyes White Dragon", "Normal"},
            {"Dark Magician", "Normal"},
            {"Armageddon Knight", "Effect"},
            {"Majesty's Fiend", "Effect"}
        };

        public static Dictionary<string, string> nameSpellTypePairs = new Dictionary<string, string>()
        {
            {"Harpie's Feather Duster", "Normal"},
            {"Polymerization", "Normal"},
            {"Tellarknight Genesis", "Quick"},
            {"Infected Mail", "Continuous"}
        };

        public static Dictionary<string, string> nameTrapTypePairs = new Dictionary<string, string>()
        {
            {"Compulsory Evacuation Device", "Normal"},
            {"Gladiator Beast War Chariot", "Counter"},
            {"Vanity's Emptiness", "Continuous"}
        };
        /// <summary>
        /// All of the "texts" are split up into short lines just so the output looks nicer.
        /// </summary>
        public static Dictionary<string, string> nameTextPairs = new Dictionary<string, string>()
        {                             
            {"Blue-Eyes White Dragon", "This legendary dragon is a powerful \n" +
                                       "engine of destruction. Virtually \n" +
                                       "invincible, very few have faced this \n" +
                                       "awesome creature and lived to tell the \n" +
                                       "tale."},
            {"Dark Magician", "The ultimate wizard in terms of attack \n" +
                              "and defense."}, 
            {"Harpie's Feather Duster", "Destroy all Spell and Trap Cards your \n" +
                                        "opponent contols."},
            {"Compulsory Evacuation Device", "Target 1 monster on the field; return \n" +
                                             "that target to the hand."},
            {"Polymerization", "Fuses 2 or more Fusion-Material \n" +
                               "Monsters to form a new Fusion Monster."},
            {"Tellarknight Genesis", "Destroy Spell/Trap Cards on the field \n" +
                                     "equal to the number of other \n" +
                                     "\"tellarknight\" cards you control."},
            {"Infected Mail", "Once per turn: You can target 1 face-up \n" +
                              "Level 4 or lower monster you control; it \n" +
                              "can attack your opponent directly this \n" +
                              "turn. Send it to the Graveyard at the \n" +
                              "end of the Battle Phase."},
            {"Gladiator Beast War Chariot", "When an Effect Monster's effect is \n" +
                                            "activated, if you control a face-up \n" +
                                            "\"Gladiator Beast\" monster: Negate the \n" +
                                            "activation and destroy it."},
            {"Armageddon Knight", "When this card is Summoned: You can \n" +
                                  "send 1 DARK monster from your deck to \n" +
                                  "the GY."},
            {"Majesty's Fiend", "Cannot be Special Summoned. Monster \n" +
                                "effects cannot be activated."},
            {"Vanity's Emptiness", "Neither player can Special Summon \n" +
                                   "monsters. If a card is sent from the \n" +
                                   "deck or the field to your Graveyrd: \n" +
                                   "Destroy this card."}
        };

        public static Dictionary<string, int> nameAtkPairs = new Dictionary<string, int>()
        {
            {"Blue-Eyes White Dragon", 3000},
            {"Dark Magician", 2500},
            {"Armageddon Knight", 1400},
            {"Majesty's Fiend", 2400}
        };

        public static Dictionary<string, int> nameDefPairs = new Dictionary<string, int>()
        {
            {"Blue-Eyes White Dragon", 2500},
            {"Dark Magician", 2100},
            {"Armageddon Knight", 1200},
            {"Majesty's Fiend", 1000}
        };


    }
}
