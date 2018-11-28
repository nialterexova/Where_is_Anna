/*var myHeading = document.querySelector('h1');
myHeading.textContent = 'Hello world!';*/

document.querySelector('h2').onclick = function() {
    alert('Ouch! Stop poking me!');
}

var myImage = document.querySelector('img');
myImage.onclick = function() {
    var mySrc = myImage.getAttribute('src');
    if(mySrc === 'image/firefox-icon.png') {
      myImage.setAttribute ('src','image/firefox-alt-icon.png');
    } else {
      myImage.setAttribute ('src','image/firefox-icon.png');
    }
}
var myButton = document.querySelector('button');
var myHeading = document.querySelector('h1');

function setUserName() {
  var myName = prompt('Please enter your name.');
  localStorage.setItem('name', myName);
  myHeading.innerHTML  = 'Mozilla приветсвует тебя, ' + myName;

if(!localStorage.getItem('name')) {
  setUserName();
} else {
  var storedName = localStorage.getItem('name');
  myHeading.innerHTML  = 'Mozilla приветсвует тебя,' + storedName;
}
}
myButton.onclick = function() {
  setUserName();
}