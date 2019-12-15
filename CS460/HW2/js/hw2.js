
class Mineral
{
    constructor(name, hardness, luster) {
        this.name = name;
        this.hardness = hardness;
        this.luster = luster;
    }
}

diamond = new Mineral("Diamond", 10, "Adamantine");
apatite = new Mineral("Apatite", 5, "Vitreous"); 
chert = new Mineral("Chert", 7, "Waxy");
limonite = new Mineral("Limonite", 3.5, "Dull");
biotite = new Mineral("Biotite Mica", 2.5, "Pearly");
opal = new Mineral("Opal", 6, "Greasy");
agate = new Mineral("Agate", 7, "Vitreous");
augite = new Mineral("Augite", 5.5, "Vitreous");
azurite = new Mineral("Azurite", 3.5, "Earthy");
corundum = new Mineral("Corundum", 9, "Adamantine");
malachite = new Mineral("Malachite", 4, "Silky");
talc = new Mineral("Talc", 1, "Pearly");
topaz = new Mineral("Topaz", 8, "Vitreous");
quartz = new Mineral("Quartz", 7, "Vitreous");
serpentine = new Mineral("Serpentine", 3, "Waxy");
hematite = new Mineral("Hematite", 1.5, "Earthy");
glauconite = new Mineral("Glauconite", 2, "Greasy");
gypsum = new Mineral("Gypsum", 2, "Silky");


var allMinerals = new Array(diamond, apatite, chert, limonite, biotite, opal, agate, augite, azurite, corundum, malachite, talc, topaz, quartz, serpentine, hematite, glauconite, gypsum);

function getMinerals(minHardness, maxHardness, luster)
{
    var result = new Array();

    if(isNaN(minHardness))
    {
        minHardness = 1;
    }
    if(isNaN(maxHardness))
    {
        maxHardness = 10;
    }
    if(luster === undefined || luster == "Any")
    {
        for(i = 0; i < allMinerals.length; i++)
        {
            if(minHardness <= allMinerals[i].hardness && maxHardness >= allMinerals[i].hardness)
            {
                result.push(allMinerals[i]);
            }
        }
    }

    for(i = 0; i < allMinerals.length; i++)
    {
        if(minHardness <= allMinerals[i].hardness &&
           maxHardness >= allMinerals[i].hardness &&
           luster == allMinerals[i].luster)
        {
            result.push(allMinerals[i]);
        }
    }
    return result;
}

function printMinerals(minerals)
{
    for(i = 0; i < minerals.length; i++)
    {
        $('#resultTableBody').append($(`
            <tr>
                <td scope="row">
                    ${minerals[i].name}
                </td>
                <td scope="row">
                    ${minerals[i].hardness}
                </td>
                <td scope="row">
                    ${minerals[i].luster}
                </td>
            </tr>`));
    }
}

$('#form').on("submit", function(event)
{
    event.preventDefault(); 
    
    var minHardness = parseFloat($('#min-hardness').val());
    
    var maxHardness = parseFloat($('#max-hardness').val());

    var luster = ($('input[name=luster]:checked').val());

    minerals = getMinerals(minHardness, maxHardness, luster);

    if(minerals.length != 0)
    {
        $('#resultTableBody').empty();

        printMinerals(minerals);

        $('#error').attr('hidden', true);

        $('#resultTable').removeAttr('hidden');
    }
    else
    {
        $('#resultTable').attr('hidden', true);

        $('#error').removeAttr('hidden');
        setTimeout(function(){
            $('#error').attr('hidden', true);}, 4000);
        
    }
})

$('#resetButton').click("button", function(event)
{
    event.preventDefault();

    location.reload();
})