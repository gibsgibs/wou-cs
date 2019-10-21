using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class State
    {
        private string label;

        private bool acceptState;

        /// <summary>
        /// Two argument constructor that sets the label to the given label, and the acceptState to the given bool value.
        /// </summary>
        /// <param name="label">
        /// The label of the state.
        /// </param>
        /// <param name="value">
        /// True or false to represent if the state is an accept state or not.
        /// </param>
        public State(string label, bool value)
        {
            this.label = label;

            acceptState = value;
        }

        /// <summary>
        /// Returns the label of the State.
        /// </summary>
        /// <returns>
        /// The label.
        /// </returns>
        public override string ToString()
        {
            return label;
        }

        /// <summary>
        /// Returns the bool value representing whether or no the state is an accept state.
        /// </summary>
        /// <returns>
        /// True or false.
        /// </returns>
        public bool GetAcceptState()
        {
            return acceptState;
        }
    }
}
