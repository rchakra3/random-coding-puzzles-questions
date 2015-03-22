//run this in the dev console

var questions = document.getElementsByClassName("entry");
var questionList='';
for (var i = 0; i <questions.length; i++)
{
  questionList+="Question "+i+")\n" +questions[i].getElementsByTagName("a")[0].getElementsByTagName("p")[0].innerHTML+ "\n\n\n\n";
}

console.log(questionList);