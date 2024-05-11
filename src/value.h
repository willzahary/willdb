#include <string>

class Value {
	union {
		int32_t int32;
		int64_t int64;
	};

public:
	typedef enum {
		INT32,
		INT64
	} value_type;
};

