
#include "Id_Manager.hpp"

std::vector<int64_t> Id_Manager::used_ids;

void Id_Manager::Mark_Id(const int64_t id)
{
	switch (used_ids.size()) {
	case 0:
		used_ids.push_back(id);
		break;
	case 1:
		if (used_ids[0] == id)
			throw repeating_id_err();
		used_ids.push_back(id);
		if (used_ids[0] > used_ids[1])
			std::swap(used_ids[0], used_ids[1]);
		break;
	default:
		auto i = std::lower_bound(used_ids.begin(), used_ids.end(), id);
		if (*i == id)
			throw repeating_id_err();
		used_ids.push_back(id);
		for (auto iter = used_ids.rbegin(); iter != std::make_reverse_iterator(i); ++i) {
			std::swap(*iter, *(iter + 1));
		}
		break;
	}
}