using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab04
{
    class SSSPath
    {
        /// <summary>
        /// Initializes the vertices so that their distance is int.MaxValue and their parent is null.
        /// </summary>
        /// <param name="G">
        /// The given Graph.
        /// </param>
        /// <param name="s">
        /// The starting vertex.
        /// </param>
        private static void InitializeSingleSource(Graph G, Vertex s)
        {
            foreach (Vertex v in G.GetVertices())
            {
                v.SetDistance(int.MaxValue);

                v.SetParent(null);
            }
            s.SetDistance(0);
        }

        /// <summary>
        /// Relaxes the given edge, according to the pseudocode in the textbook.
        /// </summary>
        /// <param name="e">
        /// The given edge.
        /// </param>
        private static void Relax(Edge e)
        {
            if (e.GetStartVertex().GetDistance() != int.MaxValue)
            {
                if (e.GetEndVertex().GetDistance() > (e.GetStartVertex().GetDistance() + e.GetWeight()))
                {
                    e.GetEndVertex().SetDistance(e.GetStartVertex().GetDistance() + e.GetWeight());

                    e.GetEndVertex().SetParent(e.GetStartVertex());
                }
            }
        }

        /// <summary>
        /// Performs the Bellman-Ford Algorithm on the given graph with the given starting vertex.
        /// </summary>
        /// <param name="G">
        /// The given graph.
        /// </param>
        /// <param name="s">
        /// The given starting vertex.
        /// </param>
        /// <returns>
        /// The string indicating whether or not there was a negative weight cycle.
        /// </returns>
        public static string BellmanFord(Graph G, Vertex s)
        {
            InitializeSingleSource(G, s);

            for (int i = 0; i < G.GetVertices().Length - 1; i++)
            {
                foreach (Edge e in G.GetEdges())
                {
                    Relax(e);
                }
            }
            foreach (Edge e in G.GetEdges())
            {
                if (e.GetStartVertex().GetDistance() != int.MaxValue)
                {
                    if (e.GetEndVertex().GetDistance() > (e.GetStartVertex().GetDistance() + e.GetWeight()))
                    {
                        return "Result of Bellman-Ford:\nNegative Weight Cycle Detected\n";
                    }
                }
            }
            return "Result of Bellman-Ford:\nNo Negative Weight Cycle Detected\n";
        }
    }
}
