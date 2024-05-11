#include <unordered_map>
#include <vector>

#include "value.h"

class Schema {
	struct column_metadata {
		int id;
		Value::value_type type;
		int size;
	};

	int column_count;

	std::unordered_map<std::string, int> column_to_id;
	std::vector<column_metadata> columns;

public:
	Schema(): column_count(0) {}

	int add_column(const char* name, Value::value_type type);
	int get_column_id(const std::string& name);
	int get_column_count();
};