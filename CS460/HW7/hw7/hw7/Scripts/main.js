var repoName;
function GetCommits(user, repo) {
    repoName = repo;
    $.ajax({
        type: "GET",
        dataType: "json",
        url: "/api/commits?user=" + user + "&repo=" + repo,
        success: successAjax,
        error: errorAjax
    })
};

function successAjax(data) {
    $('#commits div').remove();
    $('#commits').append('<div class="table-responsive pt-5"></div>');
    $('#commits div').append('<h2 class="text-center">Commits for ' + repoName + '</h2>')
    $('#commits div').append('<table class="table table-hover"></table>');
    $('#commits div table').append('<thead class="bg-dark text-light"></thead>');
    $('#commits div table thead').append('<tr><th>SHA</th><th>Timestamp</th><th>Committer</th><th>Commit Message</th></tr>');
    $('#commits div table').append('<tbody></tbody>');
    for (var i = 0; i < data.length; i++)
    {
        var $tr = $('<tr></tr>')
        $tr.append('<td><a href="' + data[i]['html_url'] + '">' + data[i]['sha'].substring(0, 8) + '</td>');
        $tr.append('<td>' + data[i]['date'] + '</td>');
        $tr.append('<td>' + data[i]['name'] + '</td>');
        $tr.append('<td>' + data[i]['message'] + '</td>');
        $('#commits table tbody').append($tr);
    }
}

function errorAjax() {
    console.log("ERROR in AJAX request.");
}