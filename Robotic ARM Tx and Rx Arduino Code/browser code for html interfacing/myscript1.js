$.ajaxSetup({timeout:1000});

var step = 0;

$.wait = function(ms) {
    var defer = $.Deferred();
    setTimeout(function() { defer.resolve(); }, ms);
    return defer;
};

function moveSrs(angle1, angle2, angle3, angle4, angle5, angle6)
{
	TextVar = myform2.inputbox.value;
	ArduinoVar = "http://" + TextVar + ":80";
	
	//add zeros
	if (angle1 < 100) {
		angle1 = "0" + angle1;
	}
	if (angle2 < 100) {
		angle2 = "0" + angle2;
	}
	if (angle3 < 100) {
		angle3 = "0" + angle3;
	}
	if (angle4 < 100) {
		angle4 = "0" + angle4;
	}
	if (angle5 < 100) {
		angle5 = "0" + angle5;
	}
	if (angle6 < 100) {
		angle6 = "0" + angle6;
	}
	if (angle1 < 10) {
		angle1 = "0" + angle1;
	}
	if (angle2 < 10) {
		angle2 = "0" + angle2;
	}
	if (angle3 < 10) {
		angle3 = "0" + angle3;
	}
	if (angle4 < 10) {
		angle4 = "0" + angle4;
	}
	if (angle5 < 10) {
		angle5 = "0" + angle5;
	}
	if (angle6 < 10) {
		angle6 = "0" + angle6;
	}
	
	//send command
	$.wait(5000).then($.get( ArduinoVar, { "srs": angle1 + " " + angle2 + " " + angle3 + " " + angle4 + " " + angle5 + " " + angle6 }, function(data){alert("data:" + data);}))	;
	{Connection: close};
	
}

//update text under scroll bars
function updateTextInput1(val) {
    document.getElementById('s1textInput').value=val;
}
function updateTextInput2(val) {
    document.getElementById('s2textInput').value=val;
}
function updateTextInput3(val) {
    document.getElementById('s3textInput').value=val;
}
function updateTextInput4(val) {
    document.getElementById('s4textInput').value=val;
}
function updateTextInput5(val) {
    document.getElementById('s5textInput').value=val;
}
function updateTextInput6(val) {
    document.getElementById('s6textInput').value=val;
}

//add command to the stack
function addCommand(val1, val2, val3, val4, val5, val6, val7) {
	document.getElementById('inputTextToSave').value = document.getElementById('inputTextToSave').value + "sr1:" + val1 + " sr2:" + val2 + " sr3:" + val3 + " sr4:" + val4 + " sr5:" + val5 + " sr6:" + val6 + " delay:" + val7 + String.fromCharCode(13, 10);
}

//clear command stack
function clearCommand() {
	document.getElementById('inputTextToSave').value = "";
}

//run command stack
function runCommands(val) {
	var k = 0;
	step = 0;
	var commands = val.split("\n"),i;
	for (i = 0; i < commands.length - 1; i++) {
			setTimeout(function(data){
				var angle1 = commands[step].split(" ")[0];
				angle1 = angle1.split(":")[1];
				var angle2 = commands[step].split(" ")[1];
				angle2 = angle2.split(":")[1];
				var angle3 = commands[step].split(" ")[2];
				angle3 = angle3.split(":")[1];
				var angle4 = commands[step].split(" ")[3];
				angle4 = angle4.split(":")[1];
				var angle5 = commands[step].split(" ")[4];
				angle5 = angle5.split(":")[1];
				var angle6 = commands[step].split(" ")[5];
				angle6 = angle6.split(":")[1];
				moveSrs(angle1, angle2, angle3, angle4, angle5, angle6);
				step+=1;
			},k);
			
			var tempo = commands[step].split(" ")[6];
			tempo = tempo.split(":")[1];
			k += parseInt(tempo);			
	}
}


//save file with actual command stack
function saveTextAsFile()
{
    var textToSave = document.getElementById("inputTextToSave").value;
    var textToSaveAsBlob = new Blob([textToSave], {type:"text/plain"});
    var textToSaveAsURL = window.URL.createObjectURL(textToSaveAsBlob);
    var fileNameToSaveAs = document.getElementById("inputFileNameToSaveAs").value;
 
    var downloadLink = document.createElement("a");
    downloadLink.download = fileNameToSaveAs;
    downloadLink.innerHTML = "Download File";
    downloadLink.href = textToSaveAsURL;
    downloadLink.onclick = destroyClickedElement;
    downloadLink.style.display = "none";
    document.body.appendChild(downloadLink);
 
    downloadLink.click();
}

function destroyClickedElement(event)
{
    document.body.removeChild(event.target);
}
 
 //load  file with a command stack
function loadFileAsText()
{
    var fileToLoad = document.getElementById("fileToLoad").files[0];
 
    var fileReader = new FileReader();
    fileReader.onload = function(fileLoadedEvent) 
    {
        var textFromFileLoaded = fileLoadedEvent.target.result;
        document.getElementById("inputTextToSave").value = textFromFileLoaded;
    };
    fileReader.readAsText(fileToLoad, "UTF-8");
}