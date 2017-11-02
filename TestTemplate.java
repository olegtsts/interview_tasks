class ValueStorage<T> {
	private T t;
	public T Get() {
		return t;
	}
	public void Set(T t) {
		this.t = t;
	}
}

public class TestTemplate {
	public static void main(String[] args) {
		ValueStorage<Integer> value_storage = new ValueStorage<Integer>();
		value_storage.Set(4);
		System.out.println(value_storage.Get());
	}
}
