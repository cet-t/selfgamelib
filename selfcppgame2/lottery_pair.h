#ifndef LOTTERY_PAIR_H
#define LOTTERY_PAIR_H

#include <vector>

using namespace std;

namespace trrne {
	template <class T_SUB>
	class lottery_pair {
	public:
		vector<T_SUB> subjects;
		vector<float> weights;

		lottery_pair() { }
		lottery_pair(T_SUB subject, float weight) {
			add(subject, weight);
		}

		void add(T_SUB subject, float weight) {
			subjects.push_back(subject);
			weights.push_back(weight);
		}

		const int length() const noexcept {
			return subjects.size();
		}
	};
}

#endif // LOTTERY_PAIR_H
