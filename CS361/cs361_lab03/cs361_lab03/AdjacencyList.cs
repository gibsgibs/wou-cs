using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab03

{   /// <summary>
    /// Sources: http://theoryofprogramming.com/adjacency-list-implementation-in-c-sharp/.
    /// </summary>
    class AdjacencyList
    {
        public LinkedList<Vertex>[] adjacencyList;

        /// <summary>
        /// Creates a new array of linked lists aof vertices.
        /// </summary>
        /// <param name="numberOfVertices">
        /// The number of vertices in the graph.
        /// </param>
        public AdjacencyList(int numberOfVertices)
        {
            adjacencyList = new LinkedList<Vertex>[numberOfVertices];

            for(int i = 0; i < numberOfVertices; i++)
            {
                adjacencyList[i] = new LinkedList<Vertex>();
            }
        }

        /// <summary>
        /// Adds an edge to the adjacency list, from the start vertex to the end vertex.
        /// </summary>
        /// <param name="startVertex">
        /// The starting vertex.
        /// </param>
        /// <param name="endVertex">
        /// The ending vertex.
        /// </param>
        public void AddEdge(Vertex startVertex, Vertex endVertex)
        {
            int location = Convert.ToInt32(startVertex.GetLabel()[0]) - 65;

            adjacencyList[location].AddLast(endVertex);
        }    
    }
}
