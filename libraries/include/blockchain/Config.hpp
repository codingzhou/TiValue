#pragma once

#include <stdint.h>

/* XXX: Comment out this line for a non-test network */
//#define TIV_TEST_NETWORK

#define TIV_TEST_NETWORK_VERSION                            83 // autogenerated

#define TIV_BLOCKCHAIN_DATABASE_VERSION                     uint64_t( 201 )

/**
 *  The address prepended to string representation of
 *  addresses.
 *
 *  Changing these parameters will result in a hard fork.
 */
#define TIV_ADDRESS_PREFIX                                  "TV"
#define TIV_BLOCKCHAIN_SYMBOL                               "TV"
#define TIV_BLOCKCHAIN_NAME                                 "Ti-Value"
#define TIV_BLOCKCHAIN_DESCRIPTION                          "Ti-Value"
			
#define TIV_BLOCKCHAIN_PRECISION                            100000

#define TIV_BLOCKCHAIN_MAX_UIA_MARKET_FEE                   10000
#define TIV_BLOCKCHAIN_BLOCK_INTERVAL_SEC                   int64_t(10)
#define TIV_BLOCKCHAIN_BLOCKS_PER_HOUR                      ((60*60)/TIV_BLOCKCHAIN_BLOCK_INTERVAL_SEC)
#define TIV_BLOCKCHAIN_BLOCKS_PER_DAY                       (TIV_BLOCKCHAIN_BLOCKS_PER_HOUR*int64_t(24))
#define TIV_BLOCKCHAIN_BLOCKS_PER_YEAR                      (TIV_BLOCKCHAIN_BLOCKS_PER_DAY*int64_t(365))

#define TIV_BLOCKCHAIN_NUM_DELEGATES                        uint32_t(8)
#define TIV_MAX_DELEGATE_PAY_PER_BLOCK                      int64_t( 0 * TIV_BLOCKCHAIN_PRECISION ) // 0 XTS
#define TIV_BLOCKCHAIN_MAX_UNDO_HISTORY                     TIV_BLOCKCHAIN_BLOCKS_PER_HOUR

#define TIV_BLOCKCHAIN_REGISTER_ACCOUNT_FEE                 int64_t( 10 * TIV_BLOCKCHAIN_PRECISION ) 

#define TIV_BLOCKCHAIN_MAX_SLATE_SIZE                       (TIV_BLOCKCHAIN_NUM_DELEGATES + (TIV_BLOCKCHAIN_NUM_DELEGATES/10))
#define TIV_BLOCKCHAIN_MAX_MESSAGE_SIZE                     2048
#define TIV_BLOCKCHAIN_MAX_FREE_MESSAGE_SIZE                1024
#define TIV_BLOCKCHAIN_MAX_SOFT_MAX_MESSAGE_SIZE            40
#define TIV_BLOCKCHAIN_MIN_MESSAGE_FEE_COE                  100
#define TIV_BLOCKCHAIN_MAX_TRANSACTION_EXPIRATION_SEC       (60*60*24*2)
#define TIV_BLOCKCHAIN_MAX_MEMO_SIZE                        19 // bytes
#define TIV_BLOCKCHAIN_EXTENDED_MEMO_SIZE                   32 // bytes
#define TIV_BLOCKCHAIN_MAX_EXTENDED_MEMO_SIZE               (TIV_BLOCKCHAIN_MAX_MEMO_SIZE + TIV_BLOCKCHAIN_EXTENDED_MEMO_SIZE)

#define TIV_DEFAULT_TRANSACTION_FEE                         1000 // XTS
#define TIV_DEFAULT_TRANSACTION_EXPIRATION_SEC              (60*60)
#define TIV_DEFAULT_CONTRACT_MARGIN                         10 * TIV_BLOCKCHAIN_PRECISION 
#define TIV_FILE_UPLOAD_CONTRACT_NAME						"File_upload"
#define TIV_FILE_UPLOAD_INTERFACE							  "Upload"
#define TIV_FILE_REJECT_INTERFACE							  "Reject"
#define TIV_FILE_ACCESS_INTERFACE						  	"Access"
#define TIV_FILE_STORE_INTERFACE						  	"Store"
#define TIV_FILE_CONFIRM_INTERFACE							"Confirm"
#define TIV_FILE_EVENT_STOREREQUEST							"StoreRequest"
#define TIV_FILE_EVENT_UPLOADREQUEST						"UploadRequest"
#define TIV_FILE_EVENT_FILESAVED						  	"FileSaved"
#define TIV_FILE_EVENT_STOREREJECT							"StoreReject"
/**
 *  The maximum amount that can be issued for user assets.
 *
 *  10^18 / 2^63 < 1  however, to support representing all share values as a double in
 *  languages like java script, we must stay within the epsilon so
 *
 *  10^15 / 2^53 < 1 allows all values to be represented as a double or an int64
 */
#define TIV_BLOCKCHAIN_MAX_SHARES                           (1000*1000*int64_t(1000)*1000*int64_t(1000))

#define TIV_BLOCKCHAIN_MIN_NAME_SIZE                        1
#define TIV_BLOCKCHAIN_MAX_NAME_SIZE                        63
#define TIV_BLOCKCHAIN_MAX_NAME_DATA_SIZE                   (1024*64)

#define TIV_BLOCKCHAIN_MAX_SUB_SYMBOL_SIZE                  8 // characters
#define TIV_BLOCKCHAIN_MIN_SYMBOL_SIZE                      3 // characters
#define TIV_BLOCKCHAIN_MAX_SYMBOL_SIZE                      12 // characters

#define TIV_BLOCKCHAIN_MIN_BURN_FEE                         TIV_BLOCKCHAIN_PRECISION * 1 // 1 XTS

#ifdef TIV_TEST_NETWORK
#define TIV_BLOCKCHAIN_VOTE_UPDATE_PERIOD_SEC               10
#else
#define TIV_BLOCKCHAIN_VOTE_UPDATE_PERIOD_SEC               (60*60) // 1 hour
#endif

#define TIV_BLOCKCHAIN_MIN_FEEDS                            ((TIV_BLOCKCHAIN_NUM_DELEGATES/2) + 1)
#define TIV_BLOCKCHAIN_MINIMUM_SHORT_ORDER_SIZE             (TIV_BLOCKCHAIN_PRECISION*100)
#define TIV_BLOCKCHAIN_MIN_YIELD_PERIOD_SEC                 (60*60*24) // 24 hours
#define TIV_BLOCKCHAIN_MAX_YIELD_PERIOD_SEC                 (TIV_BLOCKCHAIN_BLOCKS_PER_YEAR * TIV_BLOCKCHAIN_BLOCK_INTERVAL_SEC) // 1 year

#ifdef TIV_TEST_NETWORK
#define TIV_BLOCKCHAIN_MAX_SHORT_PERIOD_SEC                 (2*60*60) // 2 hours
#else
#define TIV_BLOCKCHAIN_MAX_SHORT_PERIOD_SEC                 (30*24*60*60) // 1 month
#endif
#define TIV_BLOCKCHAIN_MAX_SHORT_APR_PCT                    (uint64_t(50))

#define TIV_BLOCKCHAIN_MCALL_D2C_NUMERATOR                  1
#define TIV_BLOCKCHAIN_MCALL_D2C_DENOMINATOR                2

// TODO: This stuff only matters for propagation throttling; should go somewhere else
#define TIV_BLOCKCHAIN_DEFAULT_RELAY_FEE                    1000 // XTS
#define TIV_BLOCKCHAIN_MAX_TRX_PER_SECOND                   1000  // (1000)
#define TIV_BLOCKCHAIN_MAX_PENDING_QUEUE_SIZE               10000 // (TIV_BLOCKCHAIN_MAX_TRX_PER_SECOND * TIV_BLOCKCHAIN_BLOCK_INTERVAL_SEC)

#define TIV_BLOCKCHAIN_REVALIDATE_MAX_TRX_COUNT             (TIV_BLOCKCHAIN_MAX_TRX_PER_SECOND * TIV_BLOCKCHAIN_BLOCK_INTERVAL_SEC)


// for contract
#define  CONTRACT_ADDRESS_PREFIX "CON" 
#define  SCRIPT_ID_PREFIX "SCR" 

#define  CONTRACT_MAX_BYTECODE_SIZE   (1 * 1024 * 1024)  //just set to the limit of block size
#define  CONTRACT_MAX_NAME_SIZE  32 
#define  CONTRACT_MAX_DESCRIPTION_SIZE  256
#define  LIMIT_PRICE 1
#define  CONTRACT_PARAM_MAX_LEN  1024

#define  CONTRACT_OFFLINE_LIMIT_MAX     (1024*1024*1024) 
#define  CONTRACT_TESTING_LIMIT_MAX     (1024*1024*1024) 

// for event
#define  EVENT_PARAM_MAX_LEN  1024
#define  EVENT_TYPE_MAX_LEN   256

#define TIV_BLOCKCHAIN_FREESIGNATURE_LIMIT	10
#define TIV_BLOCKCHAIN_MAX_SIGNAGTURE_NUM   1000
#define TIV_BLOCKCHAIN_EXTRA_SIGNATURE_FEE  1000
#define TIV_BLOCKCHAIN_TRANSACTION_MAX_DEPOSIT_NUM 100

//for file store
#define  FILE_ID_PREFIX "FD" 
#define  FILE_PIECE_ID_PREFIX "FD" 
#define  TIVALUE_GETACCESS_CONTRACT_INTERFACE "GetAccess"
#define  FILE_READBUF_LENGTH 512

