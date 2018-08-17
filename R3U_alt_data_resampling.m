function [ re_data ] = R3U_alt_data_resampling( raw_data )

% /* M-FILE FUNCTION R3U_alt_data_resampling MMM R3U */
% /*==================================================================================================
% 
% ====================================================================================================
% File description:
%
%     to resample small size input data
%
% Input:
%       raw_data    -- raw data with small sampling size
% 
% Output:
%       re_data     -- resampled data
%
%
%Usage:
%       [ re_data ] = R3U_alt_data_resampling( raw_data )
%
%Example 1:
%  
%
%===================================================================================================
%  See Also:
%                R3U_alt_data_resampling
%===================================================================================================
%
%===================================================================================================
%Revision -
%Date          Name          Description of Change  email
%27-Jul-2010   Yi Chen       initial                leo.chen.yi@gmail.com
%HISTORY$
%==================================================================================================*/

%R3U_alt_data_resampling Begin

re_data         =  raw_data ./2;


%R3U_alt_data_resampling End