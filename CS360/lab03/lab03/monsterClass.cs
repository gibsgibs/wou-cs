using System;
using System.Collections.Generic;
using System.Text;

namespace lab03
{
    public class Monster : Card
    {
        private string attribute;    //these are Dark, Light, Earth, Fire, Water, Wind
        private int level;           //1-12
        private string monsterType;  //Normal, Effect, XYZ, Ritual, Syncho, etc
        private string race;         /*in the game, this is actually known as the Type with a capital "T", 
                                     but I remaned it race becuase there are a lot of instances of the word "type."
                                     These are: Warrior, Dragon, Fairy, etc*/
        private int atk;             //10-5000
        private int def;             //0-5000
        /// <summary>
        /// Default constructor sets the Monster card to "BEWD", and fills in the approriate data form the "database".
        /// </summary>
        public Monster()
        { 
                SetName("Blue-Eyes White Dragon");
                SetCardType(MyGlobals.nameCardTypePairs[GetName()]);
                attribute = MyGlobals.nameAttributePairs[GetName()];
                level = MyGlobals.nameLevelPairs[GetName()];
                race = MyGlobals.nameRacePairs[GetName()];
                monsterType = MyGlobals.nameMonsterTypePairs[GetName()];
                SetText(MyGlobals.nameTextPairs[GetName()]);
                atk = MyGlobals.nameAtkPairs[GetName()];
                def = MyGlobals.nameDefPairs[GetName()];
        }
        /// <summary>
        /// If the Monster card name exists in the list of cards, this custom constuctor creates the Monster card
        /// given by the parameter name, and fills in the approriate data form the "database". If the Monster
        /// card name is not in the list of card names, an error message is printed out to the user.
        /// </summary>
        /// <param name="name">
        /// The name of the Monster card.
        /// </param>
        public Monster(string name)
        {
            try
            {
                SetName(name);
                SetCardType(MyGlobals.nameCardTypePairs[GetName()]);
                attribute = MyGlobals.nameAttributePairs[GetName()];
                level = MyGlobals.nameLevelPairs[GetName()];
                race = MyGlobals.nameRacePairs[GetName()];
                monsterType = MyGlobals.nameMonsterTypePairs[GetName()];
                SetText(MyGlobals.nameTextPairs[GetName()]);
                atk = MyGlobals.nameAtkPairs[GetName()];
                def = MyGlobals.nameDefPairs[GetName()];
            }
            catch (Exception)
            {
                Console.WriteLine("\nNot a valid card name.\n");
            }
        }
        /// <summary>
        /// Gets the attibute of the Monster card (Dark, Light, Earth, Fire, Water, Wind), 
        /// and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the attibute.
        /// </returns>
        public string GetAttribute()
        {
            return attribute;
        }
        /// <summary>
        /// Gets the level of the Monster card (0-12), and returns the integer.
        /// </summary>
        /// <returns>
        /// The integer representing the level.
        /// </returns>
        public int GetLevel()
        {
            return level;
        }
        /// <summary>
        /// Gets the Type of Monster card (Normal, Effect, XYZ, Ritual, Syncho, etc), and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the Monster type.
        /// </returns>
        public string GetMonsterType()
        {
            return monsterType;
        }
        /// <summary>
        /// Gets the Race of Monster card (Warrior, Dragon, Fairy, etc), and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the Race.
        /// </returns>
        public string GetRace()
        {
            return race;
        }
        /// <summary>
        /// Gets the ATK of the Monster card (10-5000), and returns the integer.
        /// </summary>
        /// <returns>
        /// The integer representing the ATK.
        /// </returns>
        public int GetAtk()
        {
            return atk;
        }
        /// <summary>
        /// Gets the DEF of the Monster card (0-5000), and returns the integer.
        /// </summary>
        /// <returns>
        /// The integer representing the DEF.
        /// </returns>
        public int GetDef()
        {
            return def;
        }
        /// <summary>
        /// The overridden abstract function form the card class. It prints out the Monster card if the names of the
        /// Monster card exists in the list of card names. This is a polymorphic function.
        /// </summary>
        public override void PrintOutCard()
        {
            if (MyGlobals.allNames.Contains(GetName()))
            {
                Console.WriteLine("----------------------------------------");
                Console.WriteLine(GetName());
                Console.WriteLine(GetAttribute());
                Console.WriteLine("Level: " + GetLevel());
                Console.WriteLine("[" + GetRace() + "/" + GetMonsterType() + "]");
                Console.WriteLine("" + GetText());
                Console.WriteLine("ATK/" + GetAtk() + " DEF/" + GetDef());
                Console.WriteLine("----------------------------------------");
            }
        }
    }
}