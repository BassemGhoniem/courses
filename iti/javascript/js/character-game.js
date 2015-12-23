function charGame(str, ch) {
	var pos =[];
	if (str.indexOf(ch) === -1)
		return pos;
	
	for (var i = 0; i < str.length; i++)
		if(str[i] === ch)
			pos.push(str.indexOf(ch, i));
	return pos;
}