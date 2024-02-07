// question 1

fn is_palindrome(s: &str) -> bool {
    let reversed: String = s.chars().rev().collect();
    s == reversed
}

fn main() {
    let input = "radar";
    
    if is_palindrome(input) {
        println!("{} is a palindrome.", input);
    } else {
        println!("{} is not a palindrome.", input);
    }
}


// question 2

fn first_occurrence_index(arr: &[i32], target: i32) -> Option<usize> {
    let mut low = 0;
    let mut high = arr.len();

    while low < high {
        let mid = low + (high - low) / 2;

        if arr[mid] < target {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if low < arr.len() && arr[low] == target {
        Some(low)
    } else {
        None
    }
}

fn main() {
    // Example usage:
    let sorted_array = vec![1, 2, 2, 4, 4, 4, 5, 6, 7];
    let target_number = 4;

    match first_occurrence_index(&sorted_array, target_number) {
        Some(index) => println!("The first occurrence of {} is at index {}.", target_number, index),
        None => println!("The number {} is not present in the array.", target_number),
    }
}

// question 3

fn shortest_word(s: &str) -> Option<&str> {
    s.split_whitespace()
        .min_by_key(|word| word.len())
}

fn main() {
    // Example usage:
    let input_string = "This is a sample string with some words.";
    
    match shortest_word(input_string) {
        Some(shortest) => println!("The shortest word is: {}", shortest),
        None => println!("The input string is empty."),
    }
}

// question 4

fn is_prime(num: u64) -> bool {
    if num < 2 {
        return false;
    }

    let sqrt_num = (num as f64).sqrt() as u64;

    for i in 2..=sqrt_num {
        if num % i == 0 {
            return false; // The number is divisible by i, so it's not prime.
        }
    }

    true // The number is prime.
}

fn main() {
    // Example usage:
    let test_number = 17;

    if is_prime(test_number) {
        println!("{} is a prime number.", test_number);
    } else {
        println!("{} is not a prime number.", test_number);
    }
}

// question 5
fn find_median(sorted_array: &[i32]) -> f64 {
    let len = sorted_array.len();

    if len % 2 == 0 {
        // If the length is even, take the average of the middle two elements.
        let middle_left = sorted_array[len / 2 - 1];
        let middle_right = sorted_array[len / 2];
        return (middle_left + middle_right) as f64 / 2.0;
    } else {
        // If the length is odd, return the middle element.
        return sorted_array[len / 2] as f64;
    }
}

fn main() {
    // Example usage:
    let sorted_array = vec![1, 2, 3, 4, 5, 6, 7];
    
    let median = find_median(&sorted_array);
    
    println!("The median of the array is: {}", median);
}

// question 6
fn longest_common_prefix(strings: &[&str]) -> String {
    if strings.is_empty() {
        return String::new();
    }

    let first_string = strings[0];
    let mut common_prefix = String::new();

    for (i, char) in first_string.chars().enumerate() {
        if strings.iter().all(|s| s.len() > i && s.chars().nth(i) == Some(char)) {
            common_prefix.push(char);
        } else {
            break;
        }
    }

    common_prefix
}

fn main() {
    // Example usage:
    let string_set = vec!["apple", "appetizer", "apricot"];
    
    let common_prefix = longest_common_prefix(&string_set);
    
    println!("The longest common prefix is: {}", common_prefix);
}


// question 7
fn partition(arr: &mut [i32], low: usize, high: usize) -> usize {
    let pivot_index = (low + high) / 2;
    arr.swap(pivot_index, high);

    let mut i = low;
    for j in low..high {
        if arr[j] < arr[high] {
            arr.swap(i, j);
            i += 1;
        }
    }

    arr.swap(i, high);
    i
}

fn quickselect(arr: &mut [i32], k: usize, low: usize, high: usize) -> i32 {
    let pivot_index = partition(arr, low, high);

    if k == pivot_index {
        arr[pivot_index]
    } else if k < pivot_index {
        quickselect(arr, k, low, pivot_index - 1)
    } else {
        quickselect(arr, k, pivot_index + 1, high)
    }
}

fn kth_smallest_element(arr: &mut [i32], k: usize) -> Option<i32> {
    if k > 0 && k <= arr.len() {
        Some(quickselect(arr, k - 1, 0, arr.len() - 1))
    } else {
        None
    }
}

fn main() {
    // Example usage:
    let mut array = vec![5, 3, 1, 4, 2];
    let k = 3;

    match kth_smallest_element(&mut array, k) {
        Some(kth_smallest) => println!("The {}-th smallest element is: {}", k, kth_smallest),
        None => println!("Invalid value of k."),
    }
}

