using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab03
{
    class Vertex
    {
        private string label;

        private string color;

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

            color = null;

            distance = 0;

            parent = null;
        }

        /// <summary>
        /// Gets the label.
        /// </summary>
        /// <returns>
        /// Returns the label.
        /// </returns>
        public string GetLabel()
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
        /// Gets the color.
        /// </summary>
        /// <returns>
        /// Returns the color.
        /// </returns>
        public string GetColor()
        {
            return color;
        }

        /// <summary>
        /// Sets the color to the new color.
        /// </summary>
        /// <param name="newColor">
        /// The new color.
        /// </param>
        public void SetColor(string newColor)
        {
            color = newColor;
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

        /// <summary>
        /// Prints out all the graph information based on the vertices.
        /// </summary>
        /// <param name="vertices">
        /// The given list of vertices.
        /// </param>
        public static void PrintVertexInfo(List<Vertex> vertices)
        {
            Console.WriteLine("Vertex \t Dist. \t Par. \t Color");

            for(int i = 0; i < vertices.Count; i++)
            {
                if (vertices[i].GetParent() == null)
                {
                    Console.WriteLine(vertices[i].GetLabel() + " \t " +
                                      vertices[i].GetDistance() + " \t " +
                                      "NULL" + " \t " +
                                      vertices[i].GetColor());
                }
                else
                {
                    Console.WriteLine(vertices[i].GetLabel() + " \t " +
                                      vertices[i].GetDistance() + " \t " +
                                      vertices[i].GetParent().GetLabel() + " \t " +
                                      vertices[i].GetColor());
                }
            }
            Console.WriteLine("");
        }
    }
}
