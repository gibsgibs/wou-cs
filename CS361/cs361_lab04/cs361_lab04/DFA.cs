using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class DFA
    {
        private List<State> states;

        private State startState;

        private List<State> acceptingStates;

        private List<char> alphabet;

        private State[,] deltaTable;

        /// <summary>
        /// Five argument constructor. Sets each member variable to the given associated parameter.
        /// </summary>
        /// <param name="states">
        /// The list of States.
        /// </param>
        /// <param name="startState">
        /// The start state.
        /// </param>
        /// <param name="acceptingStates">
        /// The list of accept states.
        /// </param>
        /// <param name="alphabet">
        /// The list of chars that is the alphabet.
        /// </param>
        /// <param name="deltaTable">
        /// The 2D array of states that represents the delta table.
        /// </param>
        public DFA(List<State> states, State startState, List<State> acceptingStates, List<char> alphabet, State[,] deltaTable)
        {
            this.states = states;

            this.startState = startState;

            this.acceptingStates = acceptingStates;

            this.alphabet = alphabet;

            this.deltaTable = deltaTable;
        }

        /// <summary>
        /// Determines if a given string is accepted by the DFA.
        /// </summary>
        /// <param name="input">
        /// The given string.
        /// </param>
        /// <returns>
        /// True or false based on whether or not the current State is an accept state.
        /// </returns>
        public bool IsValidString(string input)
        {
            for(int j = 0; j < input.Length; j++)
            {
                if(!alphabet.Contains(input[j]))
                {
                    return false;
                }
            }
            int i = 0;

            State currentState = startState;

            while (i < input.Length)
            {
                for (int j = 0; j < alphabet.Count; j++)
                {
                    for (int k = 0; k < states.Count; k++)
                    {
                        if (currentState == states[k] && input[i] == alphabet[j])
                        {
                            currentState = deltaTable[k, j + 1];
                        }
                    }
                }
                i++;
            }
            return currentState.GetAcceptState();
        }

        /// <summary>
        /// Prints out the array of given strings in the first column and whether or not they were accepted in the second column.
        /// </summary>
        /// <param name="strings">
        /// The given strings to be tested.
        /// </param>
        public void ValidityOfStrings(string[] strings)
        {
            string[] columnNames = { "STRING", "ACCEPTANCE" };

            string[,] data = new string[strings.Length, columnNames.Length];

            for (int i = 0; i < strings.Length; i++)
            {
                for (int j = 0; j < columnNames.Length - 1; j++)
                {
                    data[i, j] = strings[i];

                    data[i, j + 1] = IsValidString(strings[i]).ToString();
                }
            }
            GenFunctions.PrintTable("DFA TESTING", columnNames, data);
        }

        /// <summary>
        /// Prints out the information about the DFA.
        /// </summary>
        public void PrintDFA()
        {
            Console.Write("Q = { ");

            for (int i = 0; i < states.Count; i++)
            {
                if (i != states.Count - 1)
                {
                    Console.Write(states[i].ToString() + ", ");
                }
                else
                {
                    Console.Write(states[i].ToString() + " ");
                }
            }
            Console.WriteLine("}");

            Console.WriteLine("Start state = " + startState.ToString());

            Console.Write("A = { ");

            for (int i = 0; i < acceptingStates.Count; i++)
            {
                if (i != states.Count - 1)
                {
                    Console.Write(acceptingStates[i].ToString() + ", ");
                }
                else
                {
                    Console.Write(acceptingStates[i].ToString() + " ");
                }
            }
            Console.WriteLine("}");

            Console.Write("Alphabet = { ");
            
            for (int i = 0; i < alphabet.Count; i++)
            {
                if (i != alphabet.Count - 1)
                {
                    Console.Write(alphabet[i] + ", ");
                }
                else
                {
                    Console.Write(alphabet[i] + " ");
                }
            }
            Console.WriteLine("}");

            string[,] deltaTable = GenFunctions.To2DStringArray<State>(this.deltaTable);

            string[] columnNames = new string[alphabet.Count + 1];

            for (int i = 1; i < columnNames.Length; i++)
            {
                columnNames[i] = alphabet[i - 1].ToString();
            }
            GenFunctions.PrintTable("Delta Table", columnNames, deltaTable);
        }
    }
}