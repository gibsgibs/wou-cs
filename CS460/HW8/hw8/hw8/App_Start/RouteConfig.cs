using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace hw8
{
    public class RouteConfig
    {
        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            routes.MapRoute(
                name: "Athletes",
                url: "Athletes/GetAthletes",
                defaults: new { controller = "Athletes", action = "GetAthletes" }
            );

            routes.MapRoute(
                name: "Events",
                url: "Athletes/GetEvents",
                defaults: new { controller = "Athletes", action = "GetEvents" }
            );

            routes.MapRoute(
                name: "Data",
                url: "Athletes/GraphData",
                defaults: new { controller = "Athletes", action = "GraphData"}
            );

            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional }
            );
        }
    }
}
