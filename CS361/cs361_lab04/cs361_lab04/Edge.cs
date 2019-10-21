using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class Edge
    {
        private Vertex startVertex;

        private Vertex endVertex;

        private int weight;

        /// <summary>
        /// 3 argument constructor. Sets StartVertex to the given starting vertex, 
        /// EndVertex to the given ending vertex, Weight to the given weight.
        /// </summary>
        /// <param name="startVertex">
        /// The given starting vertex.
        /// </param>
        /// <param name="endVertex">
        /// The given ending vertex.
        /// </param>
        /// <param name="weight">
        /// The given weight.
        /// </param>
        public Edge(Vertex startVertex, Vertex endVertex, int weight)
        {
            this.startVertex = startVertex;

            this.endVertex = endVertex;

            this.weight = weight;
        }

        /// <summary>
        /// Gets the StartVertex.
        /// </summary>
        /// <returns>
        /// Returns the StartVertex.
        /// </returns>
        public Vertex GetStartVertex()
        {
            return startVertex;
        }

        /// <summary>
        /// Gets the EndVertex.
        /// </summary>
        /// <returns>
        /// Returns the StartVertex.
        /// </returns>
        public Vertex GetEndVertex()
        {
            return endVertex;
        }

        /// <summary>
        /// Gets the Weight.
        /// </summary>
        /// <returns>
        /// Returns the Weight.
        /// </returns>
        public int GetWeight()
        {
            return weight;
        }

        /// <summary>
        /// Overridden ToString function for better console outputs.
        /// </summary>
        /// <returns>
        /// Returns StartVertex's ToString() followed by " -> " followed by EndVertex's
        /// </returns>
        public override string ToString()
        {
            return startVertex.ToString() + " -> " + endVertex.ToString();
        }
    }
}
