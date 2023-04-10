

function part1() {

    const options = document.querySelectorAll(".options > button")

    const corr = document.querySelector("p.response")

    for (let b of options) {

        if (b.innerText == "Javascript") {
            b.onclick = () => {
                b.style = "background-color:green"

                corr.textContent = "Correct!"
                corr.hidden = false
            }

        } else {

            b.onclick = () => {
                b.style = "background-color:red"

                corr.textContent = "Incorrect"
                corr.hidden = false
            }
        }

    }
}

function part2() {
    const possibleAnswers = ["javascript", "php"]

    const [input] = document.getElementsByTagName("input")
    const send = document.querySelector(".input > button")
    const response = document.querySelector("p.responsePart2")

    send.onclick = () => {
        const value = input.value.toLowerCase()

        if (possibleAnswers.includes(value)) {

            input.style = "background-color:green"

            response.textContent = "Correct!"
            response.hidden = false
        } else {

            input.style = "background-color:red"

            response.textContent = "Incorrect"
            response.hidden = false

        }

    }


}


document.addEventListener("DOMContentLoaded", () => {
    part1()
    part2()
})

