const Vjudge = require('vjudge-api');

const options = {
    start: 0,               // Start position from the problem-list, positive integer, default: 0
    length: 1,              // Length of the output list, positive integer with maximum 20,  default: 20
    un: 'nafisaprome',  // Username of any user, default: '' (no specific user)
    res: 1,                 // Vjudge verdict expression, default: 0 (verdicts() function might help)
    num: 'A',               // Problem number in the contest (As A, B, C,...). Default: '-' (all problems)
    language: '',           // Language of the submission, default: ''
    inContest: true,        // Default: true
    contestId: 530892       // Contest-id can be found in contest links, required.
}

Vjudge.solve_count(options)
    .then(result => console.log(result))
    .catch(err => console.error(err));