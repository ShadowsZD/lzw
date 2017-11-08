#ifndef LZWHPP
#define LZWHPP

// the codes which are taking place of the substrings
#define codeBits 12
#define tableSizeMax (0x1 << codeBits) -1 // 2^(codeBits) -1

#define prefixNULL -1

//typedef std::tuple<int, int> entry;
struct entry { 
	int prefix;
	int character; // the last char of string
	
	bool operator==(const entry &other) const {
		return (prefix == other.prefix) && (character == other.character);
	}
	
	bool operator<(const entry &other) const {
		return
			(prefix < other.prefix)
			|| (prefix == other.prefix && character < other.character);
	}
	
	entry () {}
	
	entry(int pre, int cha){
		prefix = pre;
		character = cha;
	}
};

#endif