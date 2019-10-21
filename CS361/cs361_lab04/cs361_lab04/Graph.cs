using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class Graph
    {
        private string label;

        private Vertex[] vertices;

        private Edge[] edges;

        /// <summary>
        /// 3 argument constructor. Sets Label to the given label, Vertices to the
        /// given vertices, and Edges to the given edges.
        /// </summary>
        /// <param name="label">
        /// The given label.
        /// </param>
        /// <param name="vertices">
        /// The given array of vertices.
        /// </param>
        /// <param name="edges">
        /// The given array of edges.
        /// </param>
        public Graph(string label, Vertex[] vertices, Edge[] edges)
        {
            this.label = label;

            this.vertices = vertices;

            this.edges = edges;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns>
        /// 
        /// </returns>
        public Vertex[] GetVertices()
        {
            return vertices;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns>
        /// 
        /// </returns>
        public Edge[] GetEdges()
        {
            return edges;
        }

        /// <summary>
        /// Overridden ToString function for better console outputs.
        /// </summary>
        /// <returns>
        /// Returns the Label.
        /// </returns>
        public override string ToString()
        {
            return label;
        }

        /// <summary>
        /// Prints out the vertices, edges, and weights of the graph.
        /// </summary>
        public void PrintGraph(string label)
        {
            int longest = edges.Length;

            if(vertices.Length > longest)
            {
                longest = vertices.Length;
            }
            string[,] graphTable = new string[longest,5];

            for(int i = 0; i < vertices.Length; i++)
            {
                if (vertices[i].GetParent() == null)
                {
                    graphTable[i, 0] = vertices[i].ToString();
                    graphTable[i, 1] = "NULL";
                    graphTable[i, 2] = vertices[i].GetDistance().ToString();
                }
                else
                {
                    graphTable[i, 0] = vertices[i].ToString();
                    graphTable[i, 1] = vertices[i].GetParent().ToString();
                    graphTable[i, 2] = vertices[i].GetDistance().ToString();
                }
            }
            for(int i = 0; i < edges.Length; i++)
            {
                graphTable[i, 3] = edges[i].ToString();

                graphTable[i, 4] = edges[i].GetWeight().ToString();
            }
            string[] columnNames = { "VERTICES", "PARENT", "DISTANCE", "EDGES", "WEIGHTS" };

            GenFunctions.PrintTable("Graph " + this.label + ": " + label, columnNames, graphTable);
        }
    }
}
