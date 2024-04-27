#ifndef TEMPLATE_H
#define TEMPLATE_H

/**
 * @brief Length of codeword.
 * 
 * @return int 
 */
int n();

/**
 * @brief Length of message.
 * 
 * @return int 
 */
int k();

/**
 * @brief Encode msg to codeword.
 * 
 * @param msg length of msg should be `k()`.
 * @param codeword length of codeword should be `n()`. No restriction on content.
 */
void encode(const int msg[], int codeword[]);

/**
 * @brief Decode codeword to msg.
 * 
 * @param codeword length of codeword should be `n()`.
 * @param msg length of msg should be `k()`. No restriction on content.
 */
void decode(const int codeword[], int msg[]);

#endif