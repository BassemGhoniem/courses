function mario(n) {
	for (var i = 0; i < n; i++) {
		var result = ""
		for (var j = 0; j < n - i; j++)
			result += " ";
		for (var j = 0; j < i + 1; j++)
			result += "#";
		console.log(result);
	}
}