using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab03
{
    class Searches
    {
        /// <summary>
        /// Uses the breadth first search algorithm on an adacency list representation of a graph.
        /// </summary>
        /// <param name="adjencyList">
        /// The adjacency representation of a graph.
        /// </param>
        /// <param name="vertices">
        /// A list of the vertices in the graph.
        /// </param>
        /// <param name="startingVertex">
        /// The starting vertex.
        /// </param>
        public static void BreadthFitstSearch_al(AdjacencyList adjencyList, List<Vertex> vertices, Vertex startingVertex)
        {
            for(int i = 0; i < vertices.Count; i++)
            {
                vertices.ElementAt(i).SetColor("WHITE");

                vertices.ElementAt(i).SetDistance(int.MaxValue);

                vertices.ElementAt(i).SetParent(null);
            }
            startingVertex.SetColor("GRAY");

            startingVertex.SetDistance(0);

            startingVertex.SetParent(null);

            Queue<Vertex> queue = new Queue<Vertex>();

            queue.Enqueue(startingVertex);

            while(queue.Count() != 0)
            {
                Vertex u = queue.Dequeue();

                int location = Convert.ToInt32(u.GetLabel()[0]) - 65;

                foreach (Vertex v in adjencyList.adjacencyList[location])
                {
                    if(v.GetColor() == "WHITE")
                    {
                        v.SetColor("GRAY");

                        v.SetDistance(u.GetDistance() + 1);

                        v.SetParent(u);

                        queue.Enqueue(v);
                    }
                }
                u.SetColor("BLACK");
            }
                                   
        }

        /// <summary>
        /// Uses the breadth first search algorithm on an adacency matrix representation of a graph.
        /// </summary>
        /// <param name="adjacencyMatrix">
        /// The given adjacency matrix representaion of a graph.
        /// </param>
        /// <returns>
        /// The resulting graph after the breadth first traversal is performed.
        /// </returns>
        public static int[,] BreadthFirstSearch_am(int[,] adjacencyMatrix)
        {
            int m = adjacencyMatrix.GetLength(0);

            int n = adjacencyMatrix.GetLength(1);

            int[,] result = new int[m, n];

            PriorityQueue<int> queue = new PriorityQueue<int>();

            PriorityQueue<int> vertices = new PriorityQueue<int>();

            int i = 0;

            queue.Enqueue(i);

            for(int j = 1; j < m; j++)
            {
                if(adjacencyMatrix[i, j] == 1)
                {
                    result[i, j] = 1;

                    result[j, i] = 1;

                    queue.Enqueue(j);

                    vertices.Enqueue(j);
                }
                vertices.Enqueue(i);
            }
            while(queue.Count() != 0)
            {
                i = queue.Dequeue();

                for(int k = 0; k < m; k++)
                {
                    if(adjacencyMatrix[i, k] == 1 && !vertices.Contains(k))
                    {
                        result[i, k] = 1;

                        result[k, i] = 1;

                        queue.Enqueue(k);

                        vertices.Enqueue(k);
                    }
                }
            }
            return result;
        }
    }
}

