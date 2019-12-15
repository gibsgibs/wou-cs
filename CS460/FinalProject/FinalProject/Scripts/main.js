var ajax_call = function () {
    var id = $('#EventID').text();
    console.log(id);
    $.ajax({
        type: "GET",
        dataTable: "json",
        url: "/Event/RSVPs?id=" + id,
        success: successAjax,
        error: errorAjax
    })
};

function successAjax(data) {
    var count = data.length
    $('#countId').remove();
    $('#count').append('<div class="text-center text-danger h1" id="countId">' + count + '</div>');
};
function errorAjax() {
    console.log("ERROR in AJAX request.");
};
var interval = 5000;
window.setInterval(ajax_call, interval);