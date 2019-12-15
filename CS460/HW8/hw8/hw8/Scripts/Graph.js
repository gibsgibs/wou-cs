// Lots of help from Tiffany J.

function getSelectOptions(json, id) {
    var $select = $('#' + id);
    var i = 0;
    while (i < json.length) {
        var $option = $('<option value=' + json[i]["id"] + '>' + json[i]["name"] + '</option>');
        $select.append($option);
        i++;
    }
    $select.show();
    return $select;
}

function revertToDefault(id) {
    var $element = $('#' + id);
    $element.empty();
    $element.append('<option selected value = "null">Select</option>');
}

$('#listOfTeams').change(function () {
    revertToDefault('listOfAthletes');
    revertToDefault('listOfEvents');
    var id = $(this)[0].value;
    $.ajax({
        type: "GET",
        dataTable: "json",
        url: "/Athletes/GetAthletes?id=" + id,
        success: getAthletes,
        error: errorAjax
    })
})

function getAthletes(data) {
    $('#listOfAthletes').append(getSelectOptions(data, "listOfAthletes"));
}

$('#listOfAthletes').change(function () {
    revertToDefault('listOfEvents');
    var id = $(this)[0].value;
    $.ajax({
        type: "GET",
        dataTable: "json",
        url: "/Athletes/GetEvents?id=" + id,
        success: getEvents,
        error: errorAjax
    });
});

function getEvents(data) {
    $('#listOfEvents').append(getSelectOptions(data, "listOfEvents"));
}

$('#listOfEvents').change(function () {
    var id = $(this)[0].value;
    var athlete = $('#listOfAthletes')[0].value;
    $.ajax({
        type: "GET",
        dataTable: "json",
        url: "/Athletes/GraphData?id=" + id + "&athleteID=" + athlete,
        success: makeGraph,
        error: errorAjax
    });
});

function makeGraph(data) {
    var dates = [];
    var times = [];
    var i = 0;
    while (i < data.length) {
        dates[i] = data[i]["Date"];
        times[i] = data[i]["Time"];
        i++;
    }
    var trace = {
        x: dates,
        y: times,
        type: 'scatter'
    };
    var plotData = [trace];
    var layout = {
        title: {
            text: "Event Time vs. Meet Date"
        },
        xaxis: {
            title: {
                text: "Meet Dates"
            }
        },
        yaxis: {
            title: {
                text: "Event Times"
            }
        }
    };
    Plotly.newPlot('thePlot', plotData, layout);
}

function errorAjax() {
    console.log("ERROR in AJAX request.");
}