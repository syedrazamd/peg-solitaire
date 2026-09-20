let allblocks = document.querySelectorAll('.block');
let blocks = document.querySelectorAll('.block:not(.invalid)');
let selected_peg = null;
blocks.forEach(block => {
    block.addEventListener('click', () => {
        play();
    });
    function check_moves(valid_moves_pegs){
        return true;
    }
    function play() {
            const curr = document.querySelector('.block.curr');
            if (curr) {
                curr.classList.remove('curr');
            }
            block.classList.add('curr');
            if (block.classList.contains('peg')) {
                selected_peg = block;
            }
            else {
                if (selected_peg) {
                    let selected_peg_row = Number(selected_peg.dataset.row);
                    let selected_peg_column = Number(selected_peg.dataset.column);
                    let destination_row = Number(block.dataset.row);
                    let destination_column = Number(block.dataset.column);
                    if (selected_peg_column === destination_column && Math.abs(selected_peg_row - destination_row) === 2) {

                        let mid_row = (selected_peg_row + destination_row) / 2;
                        let mid_column = selected_peg_column;
                        let element = document.querySelector(`[data-row="${mid_row}"][data-column="${mid_column}"]`);
                        if (element.classList.contains('peg')) {
                            selected_peg.classList.remove('peg');
                            element.classList.remove('peg');
                            let dest = document.querySelector(`[data-row="${destination_row}"][data-column="${destination_column}"]`);
                            dest.classList.add('peg');
                             if (document.querySelectorAll('.peg').length === 1) {
                                document.querySelector('.result-won').classList.remove('hidden');
                            }
                        }

                    }
                    else if (selected_peg_row === destination_row && Math.abs(selected_peg_column - destination_column) === 2) {
                        let mid_column = (selected_peg_column + destination_column) / 2;
                        let mid_row = selected_peg_row;
                        let element = document.querySelector(`[data-row="${mid_row}"][data-column="${mid_column}"]`);
                        if (element.classList.contains('peg')) {
                            selected_peg.classList.remove('peg');
                            element.classList.remove('peg');
                            let dest = document.querySelector(`[data-row="${destination_row}"][data-column="${destination_column}"]`);
                            dest.classList.add('peg');
                            if (document.querySelectorAll('.peg').length === 1) {
                                document.querySelector('.result-won').classList.remove('hidden');
                            }
                        }
                    }
                }
            }
    }
        console.log(block.dataset.row, block.dataset.column);
    });
allblocks.forEach((block, index) => {
    const columns = index % 7;
    const rows = Math.floor(index / 7);
    console.log(rows, columns);
    block.setAttribute('data-row', rows);
    block.setAttribute('data-column', columns);
});

