function bottle (names) {
	if (names.length == 0)
		return [-1, -1];
	var x, z;
	do {
		x = Math.floor(Math.random() * names.length);
		z = Math.floor(Math.random() * names.length);
	} while (x === z);
	return [names[x], names[z]];
}