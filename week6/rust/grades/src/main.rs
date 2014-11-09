use std::io;

fn addGrade(grade: uint, gradeArray: &mut [int]) {
    gradeArray[grade] += 1;
}

fn printGrades(gradeArray: &[int]) {
    for x in range(0u, 6u) {
        println!("{} grades of {}", gradeArray[x], x);
    }
    
}

fn main() {

    let mut gradeArray = [0i, ..6]; 

    println!("Please enter grades 0-5, one by one.");
    println!("When you are finished, type 'quit'");

    loop {
        io::stdio::print("Grade please: ");
        let input = io::stdin().read_line().ok().expect("Failed to read line");

        let input_num: Option<uint> = from_str(input.as_slice().trim());

        let num = match input_num {
            Some(num) => num,
            None      => {
                if input.as_slice().trim() == "quit" {
                    printGrades(gradeArray);
                    break;
                } else {
                    println!("Invalid number!");
                    continue;
                }
            }
        };
        if (num >= 0) && (num < 6) { 
            addGrade(num, gradeArray);
        } else {
            println!("Invalid number!");
        }
    }
}
