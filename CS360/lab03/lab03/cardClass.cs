using System;
using System.Collections.Generic;
using System.Text;

namespace lab03
{   
    public abstract class Card
    {
        private string name;     //the name of the card.
        private string cardType; //types are: Monster, Spell, Trap.
        private string text;     //texts are effects and descriptions.
        /// <summary>
        /// Gets the name of the Card, and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the name of the Card.
        /// </returns>
        protected string GetName()
        {
            return name;
        }
        /// <summary>
        /// Sets the name of the Card, given the new name.
        /// </summary>
        /// <param name="newName">
        /// The new name for the Card.
        /// </param>
        protected void SetName(string newName)
        {
            name = newName;
        }
        /// <summary>
        /// Gets the Type of the Card (Monster, Spell, Trap), and returns the string.
        /// </summary>
        /// <returns>
        /// The string representing the name of the Card.
        /// </returns>
        protected string GetCardType()
        {
            return cardType;
        }
        /// <summary>
        /// Sets the Type of the Card (Monster, Spell, Trap), given the new type.
        /// </summary>
        /// <param name="newType">
        /// The new type for the Card.
        /// </param>
        protected void SetCardType(string newType)
        {
            cardType = newType;
        }
        /// <summary>
        /// Gets the Text for the card (Desciptive text, or Effect text).
        /// </summary>
        /// <returns>
        /// The string representing the Text for the Card.
        /// </returns>
        protected string GetText()
        {
            return text;
        }
        /// <summary>
        /// Sets the Text for the Card (Desciptive text, or Effect text), given the new Text.
        /// </summary>
        /// <param name="newText">
        /// The new Text for the Card.
        /// </param>
        protected void SetText(string newText)
        {
            text = newText;
        }
        /// <summary>
        /// The abstract print fucntion that will be overridden in the children classes.
        /// </summary>
        public abstract void PrintOutCard();
    }
}