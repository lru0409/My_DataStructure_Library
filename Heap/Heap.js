class Heap {
	constructor(compare) {
		this.heap = [];
		this.compare = compare;
	}

	getParentIndex(index) {
		return Math.floor((index - 1) / 2);
	}

	getLeftChildIndex(index) {
		return index * 2 + 1;
	}

	getRightChildIndex(index) {
		return index * 2 + 2;
	}

	swap(index1, index2) {
		const temp = this.heap[index1];
		this.heap[index1] = this.heap[index2];
		this.heap[index2] = temp;
	}

	push(value) {
		this.heap.push(value);
		this.heapifyUp();
	}

	heapifyUp() {
		let index = this.heap.length - 1;
		while (true) {
			let parentIndex = this.getParentIndex(index);
			if (parentIndex < 0)
				break;
			if (this.compare(this.heap[parentIndex], this.heap[index]) <= 0)
				break;
			this.swap(index, parentIndex);
			index = parentIndex;
		}
	}

	pop() {
		if (this.heap.length === 0) {
			return null;
		}
		if (this.heap.length === 1) {
			return this.heap.pop();
		}
		const ret = this.heap[0];
		this.heap[0] = this.heap.pop();
		this.heapifyDown();
		return ret;
	}

	heapifyDown() {
		let index = 0;

		while (true) {
			let leftChildIndex = this.getLeftChildIndex(index);
			let rightChildIndex = this.getRightChildIndex(index);
			
			let highPriorityChildIndex;
			if (leftChildIndex >= this.heap.length) { // child가 없음
				break;
			} else if (rightChildIndex >= this.heap.length) { // left child만 있음
				highPriorityChildIndex = leftChildIndex;
			} else { // left, right 둘 중 우선순위가 더 높은 것 선택
				if (this.compare(this.heap[leftChildIndex], this.heap[rightChildIndex]) <= 0)
					highPriorityChildIndex = leftChildIndex;
				else
					highPriorityChildIndex = rightChildIndex;
			}

			if (this.compare(this.heap[index], this.heap[highPriorityChildIndex]) <= 0)
				break;
			this.swap(index, highPriorityChildIndex);
			index = highPriorityChildIndex;
		}
	}

	peek() {
		return this.heap.length === 0 ? null : this.heap[0];
	}

	size() {
		return this.heap.length;
	}
}

export default Heap;