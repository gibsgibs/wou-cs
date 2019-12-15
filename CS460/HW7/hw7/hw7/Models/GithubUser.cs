using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Newtonsoft.Json.Linq;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace hw7.Models
{
    public class GithubUser
    {
        public GithubUser(JObject jObject)
        {
            avatarUrl = jObject.Value<string>("avatar_url");
            name = jObject.Value<string>("name");
            userName = jObject.Value<string>("login");
            email = jObject.Value<string>("email");
            bio = jObject.Value<string>("bio");
            location = jObject.Value<string>("location");
            homepage = jObject.Value<string>("html_url");
        }
        public string avatarUrl { get; set; }
        public string name { get; set; }
        public string userName { get; set; }
        public string email { get; set; }
        public string bio { get; set; }
        public string location { get; set; }
        public List<GithubRepo> githubRepos { get; set; }
        public string homepage { get; set; }
    }
}