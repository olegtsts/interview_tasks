public class HashTableTest {
	public static void main(String[] args) {
		java.util.HashMap<String, String> hashmap = new java.util.HashMap<String, String>();
		hashmap.put("123", "456");
		System.out.println(hashmap.get("123456"));
		if (hashmap.containsKey("123")) {
			System.out.println("hashmap contains key");
		} else {
			System.out.println("hashmap does not contain key");
		}
	}
};
