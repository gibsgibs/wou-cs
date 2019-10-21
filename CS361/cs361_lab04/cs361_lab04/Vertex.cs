using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class Vertex
    {
        private string label;

        private int distance;

        private Vertex parent;

        /// <summary>
        /// Single argument constructor. Sets the label to the given label, the color and parent to null, and the distance to 0.
        /// </summary>
        /// <param name="myLabel">
        /// The given label.
        /// </param>
        public Vertex(string myLabel)
        {
            label = myLabel;

            distance = 0;

            parent = null;
        }

        /// <summary>
        /// Overridden ToString function for better console outputs.
        /// </summary>
        /// <returns>
        /// Returns the label.
        /// </returns>
        public override string ToString()
        {
            return label;
        }

        /// <summary>
        /// Sets the label to the given label.
        /// </summary>
        /// <param name="newLabel">
        /// The given label.
        /// </param>
        public void SetLabel(string newLabel)
        {
            label = newLabel;
        }

        /// <summary>
        /// Gets the distance.
        /// </summary>
        /// <returns>
        /// Returns the distance.
        /// </returns>
        public int GetDistance()
        {
            return distance;
        }

        /// <summary>
        /// Sets the distance.
        /// </summary>
        /// <param name="newDistance">
        /// The new distance.
        /// </param>
        public void SetDistance(int newDistance)
        {
            distance = newDistance;
        }

        /// <summary>
        /// Gets the parent vertex.
        /// </summary>
        /// <returns>
        /// Returns the parent vertex.
        /// </returns>
        public Vertex GetParent()
        {
            return parent;
        }

        /// <summary>
        /// Sets the parent vertex to the new parent vertex.
        /// </summary>
        /// <param name="newParent">
        /// The new parent vertex.
        /// </param>
        public void SetParent(Vertex newParent)
        {
            parent = newParent;
        }
    }
}
