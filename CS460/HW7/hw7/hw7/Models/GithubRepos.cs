using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Newtonsoft.Json.Linq;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace hw7.Models
{
    public class GithubRepo
    {
        public GithubRepo(JToken jToken)
        {
            repoName = (string)jToken["name"];
            ownerName = (string)jToken["owner"]["login"];
            ownerAvatarLink = (string)jToken["owner"]["avatar_url"];
            timeSinceLastCommit = GetTimeSinceLastCommit(jToken);
            repoPage = (string)jToken["html_url"];

        }
        public string repoName { get; set; }
        [Display(Name = "Owner")]
        public string ownerName { get; set; }
        public string ownerAvatarLink { get; set; }
        public string timeSinceLastCommit { get; set; }
        public string repoPage { get; set; }
        public string GetTimeSinceLastCommit(JToken jToken)
        {
            DateTime updatedAt = DateTime.Parse((string)jToken["updated_at"]);
            return $"Last commited {(DateTime.Now.ToLocalTime().Date - updatedAt.ToLocalTime().Date).Days} days ago";
        }
    }
}