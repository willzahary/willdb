#include <iostream>

#include "schema.h"

int Schema::add_column(const char *name, Value::value_type type) {
	int column_id = column_to_id.size();

	if (column_to_id.count(name)) {
		// column name already exists
		return -1;
	}

	column_metadata metadata;
	metadata.id = column_id;
	metadata.type = type;

	switch (type) {
		case Value::INT32:
			metadata.size = 32;
			break;
		case Value::INT64:
			metadata.size = 64;
			break;
		default:
			metadata.size = -1;
	}

	column_to_id[name] = column_id;
	columns.push_back(metadata);
	column_count++;
	return column_id;
}

int Schema::get_column_id(const std::string& name) {
	if (!column_to_id.count(name)) {
		// column not in schema
		return -1;
	}
	return column_to_id[name];
}

int Schema::get_column_count() {
	return column_count;
}