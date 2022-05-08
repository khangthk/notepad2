#include "EditLexer.h"
#include "EditStyleX.h"

static KEYWORDLIST Keywords_Julia = {{
//++Autogenerated -- start of section automatically generated
"abstract baremodule begin break catch const continue do else elseif end export finally for function global "
"if import in isa let local macro module mutable primitive quote return struct try type using var where while "

, // 1 code folding
"baremodule begin do for function if let macro module quote struct try type while "

, // 2 type
"AbstractArray AbstractArrayStyle AbstractChannel AbstractChar AbstractDict AbstractDisplay AbstractFloat "
"AbstractIrrational AbstractLock AbstractLogger AbstractMatrix AbstractRNG AbstractRange "
"AbstractSet AbstractSparseArray AbstractSparseMatrix AbstractSparseVector AbstractString AbstractUnitRange "
"AbstractVecOrMat AbstractVector AbstractWorkerPool Adjoint Anonymous Any ArgumentError Array ArrayStyle "
"AssertionError AsyncCondition Atomic "
"Base64DecodePipe Base64EncodePipe Bidiagonal BigFloat BigInt BitArray BitMatrix BitSet BitVector Bool BoundsError "
"BroadcastStyle "
"CFunction CapturedException CartesianIndex CartesianIndices Cchar Cdouble Cfloat Channel Char Cint Cintmax_t "
"Clong Clonglong ClusterManager Cmd "
"Colon Complex ComplexF16 ComplexF32 ComplexF64 CompositeException CompoundPeriod Condition ConsoleLogger Cptrdiff_t "
"Cshort Csize_t Cssize_t Cstring Cuchar Cuint Cuintmax_t Culong Culonglong Cushort Cwchar_t Cwstring "
"DataType Date DateFormat DateTime Day DefaultArrayStyle DenseArray DenseMatrix DenseVecOrMat DenseVector "
"Diagonal Dict DimensionMismatch Dims DivideError DomainError "
"EOFError Enum EnvDict ErrorException Event Exception ExponentialBackOff Expr Float16 Float32 Float64 Function Future "
"Givens GlobalRef Hermitian Hour "
"IO IOBuffer IOContext IOStream IPAddr IPv4 IPv6 IdDict ImmutableDict IndexCartesian IndexLinear IndexStyle InexactError "
"InitError Instant Int Int128 Int16 Int32 Int64 Int8 Integer InterruptException InvalidStateException Irrational "
"IteratorEltype IteratorSize "
"KeyError LinRange LineNumberNode LinearIndices LoadError LogLevel LowerTriangular "
"MIME Matrix MersenneTwister Method MethodError Microsecond Millisecond Minute Missing MissingException Module Month "
"Mutex "
"NTuple NamedTuple Nanosecond Nothing NullLogger Number OneTo OrdinalRange OutOfMemoryError OverflowError "
"Pair Pairs PartialQuickSort Period PermutedDimsArray Pipe PipeBuffer PosDefException ProcessFailedException Ptr "
"QR QRCompactWY QRPivoted QuoteNode "
"Random RandomDevice Rational RawFD "
"ReadOnlyMemoryError Real ReentrantLock Ref Regex RegexMatch RemoteChannel RemoteException RoundingMode "
"Second SegmentationFault Semaphore Serialization Set SharedArray SharedMatrix SharedVector "
"Signed SimpleLogger SingularException Some SparseMatrixCSC SparseVector SpinLock "
"StackFrame StackOverflowError StackTrace Stateful StepRange StepRangeLen "
"StridedArray StridedMatrix StridedVecOrMat StridedVector String StringIndexError SubArray SubString SubstitutionString "
"SymTridiagonal Symbol Symmetric SystemError "
"TCPSocket Task TextDisplay Time TimeType Timer TmStruct Transpose Tridiagonal Tuple Type TypeError TypeVar "
"UDPSocket UInt UInt128 UInt16 UInt32 UInt64 UInt8 UTInstant "
"UndefInitializer UndefKeywordError UndefRefError UndefVarError "
"UniformScaling Union UnionAll UnitLowerTriangular UnitRange UnitUpperTriangular Unsigned UpperTriangular "
"Val Vararg VecElement VecOrMat Vector VersionNumber WeakKeyDict WeakRef Week WorkerConfig WorkerPool Year "

, // 3 constant
"ARCH ARGS BINDIR CPU_THREADS C_NULL Cvoid DEPOT_PATH ENDIAN_BOM ENV Inf Inf16 Inf32 Inf64 InsertionSort KERNEL "
"LOAD_PATH MACHINE MergeSort NaN NaN16 NaN32 NaN64 PROGRAM_FILE QuickSort "
"RoundDown RoundFromZero RoundNearest RoundNearestTiesAway RoundNearestTiesUp RoundToZero RoundUp VERSION WORD_SIZE ans "
"catalan devnull eulergamma false golden im missing nothing pi stderr stdin stdout true undef "

, // 4 basic function
"applicable( ccall( complex( error( eval( fieldtype( float( getfield( ifelse( include( invoke( isa( isdefined( "
"nameof( new( nfields( print( println( repr( rethrow( setfield!( show( signed( sizeof( string( "
"throw( tuple( typeassert( typeof( unsigned( "

, // 5 module
"Base Base64 Broadcast CRC32c Checked Core CoreLogging Dates DelimitedFiles Distributed Docs "
"FastMath FileWatching Filesystem GC Grisu Intrinsics Iterators IteratorsMD Libc LinearAlgebra "
"MPFR Main Math MathConstants Meta Mmap Multimedia Printf Profile Rounding "
"SharedArrays Sockets Sort SparseArrays StackTraces Statistics Sys Test Threads UUIDs Unicode "

, // 6 macro
"allocated assert async boundscheck cfunction debug deprecate distributed dump "
"elapsed enum error eval evalpoly everywhere fastmath fetch generated gensym goto "
"inbounds inferred info inline isdefined label logmsg lower macroexpand macroexpand1 noinline nospecialize "
"polly preserve printf profile propagate_inbounds pure show spawn spawnat specialize sprintf static sync "
"task test test_broken test_deprecated test_logs test_nowarn test_skip test_throws test_warn testset threads "
"time timed timev "
"view views warn "

, // 7 function
"abs( abs2( abspath( "
"accept( accumulate!( accumulate( acos( acosd( acosh( acot( acotd( acoth( acquire( acsc( acscd( acsch( "
"add_with_overflow( addprocs( adjoint!( adjoint( all!( all( allunique( angle( any!( any( append!( argmax( argmin( "
"ascii( asec( asecd( asech( asin( asind( asinh( asyncmap!( asyncmap( atan( atand( atanh( atexit( "
"atomic_add!( atomic_and!( atomic_cas!( atomic_fence( atomic_max!( atomic_min!( atomic_nand!( atomic_or!( atomic_sub!( "
"atomic_xchg!( atomic_xor!( axes( "
"backtrace( base64decode( base64encode( basename( big( bind( binomial( bitrand( bitstring( blockdiag( "
"broadcast!( broadcast( broadcastable( bswap( bunchkaufman!( bunchkaufman( bytes2hex( bytesavailable( "
"callers( calloc( cat( catch_backtrace( catch_exceptions( catch_stack( cbrt( cconvert( cd( ceil( cglobal( "
"channel_from_id( checkbounds( checked_abs( checked_add( checked_cld( checked_div( checked_fld( "
"checked_mod( checked_mul( checked_neg( checked_rem( checked_sub( checkindex( checksquare( chmod( "
"cholesky!( cholesky( chomp( chop( chown( circcopy!( circshift!( circshift( cis( "
"clamp!( clamp( cld( clear!( clear( clear_malloc_data( close( cluster_cookie( cmp( coalesce( "
"code_lowered( code_typed( codepoint( codeunit( codeunits( collect( combine_axes( combine_styles( compilecache( "
"cond( condskeel( conj!( conj( connect( convert( copy( copysign( copyto!( cor( cos( cosc( cosd( cosh( cospi( "
"cot( cotd( coth( count( count_ones( count_zeros( countfrom( countlines( cov( cp( crc32c( cross( csc( cscd( csch( ctime( "
"cumprod!( cumprod( cumsum!( cumsum( current_logger( current_task( cycle( "
"datatype_alignment( datatype_haspadding( datatype_pointerfree( "
"date2epochdays( datetime2epochms( datetime2julian( datetime2rata( datetime2unix( day( dayabbr( dayname( "
"dayofmonth( dayofquarter( dayofweek( dayofweekofmonth( dayofyear( daysinmonth( daysinyear( daysofweekinmonth( "
"deepcopy( default( default_worker_pool( deg2rad( delete!( deleteat!( denominator( deserialize( det( detach( "
"diag( diagind( diagm( diff( digits!( digits( dirname( "
"disable_logging( disable_sigint( display( displayable( displaysize( div( divrem( dot( download( "
"drop( dropdims( droptol!( dropzeros!( dropzeros( dump( "
"eachindex( eachline( eachmatch( eigen!( eigen( eigmax( eigmin( eigvals!( eigvals( eigvecs( eltype( empty!( "
"enable( endswith( enumerate( eof( epochdays2date( epochms2datetime( eps( errno( esc( escape_string( evalfile( "
"exit( exp( exp10( exp2( expanduser( expm1( exponent( extrema( "
"factorial( factorize( falses( fd( fdio( fetch( fieldcount( fieldname( fieldnames( fieldoffset( fieldtypes( "
"filemode( filesize( fill!( fill( filter!( filter( finalize( finalizer( "
"findall( findfirst( findlast( findmax!( findmax( findmin!( findmin( findnext( findnz( findprev( finish( "
"first( firstdayofmonth( firstdayofquarter( firstdayofweek( firstdayofyear( firstindex( "
"flatten( fld( fldmod( fldmod1( flipsign( floatmax( floatmin( floor( floorceil( flush( flush_cstdio( fma( "
"foldl( foldr( foreach( format( free( frexp( front( fullname( functionloc( "
"gc( gcd( gcdx( gensym( get!( get( get_process_title( get_testset( get_testset_depth( get_zero_subnormals( "
"getalladdrinfo( gethostname( getindex( getipaddr( getipaddrs( getkey( getnameinfo( getpeername( getpid( getproperty( "
"getsockname( givens( global_logger( gperm( graphemes( "
"handle_message( hasfield( hash( haskey( hasmethod( hasproperty( hcat( hessenberg!( hessenberg( hex2bytes!( hex2bytes( "
"homedir( hour( htol( hton( hvcat( hypot( "
"identity( ignorestatus( imag( in( include_dependency( include_string( indexin( indexpids( init( init_worker( "
"insert!( instances( interrupt( intersect!( intersect( inv( invmod( invokelatest( invperm( "
"isabspath( isabstracttype( isapprox( isascii( isassigned( isbits( isbitstype( isblockdev( "
"ischardev( iscntrl( isconcretetype( isconst( isdiag( isdigit( isdir( isdirpath( isdispatchtuple( "
"isempty( isequal( iseven( isfifo( isfile( isfinite( ishermitian( isimmutable( isinf( isinteger( isinteractive( "
"isleapyear( isless( isletter( islink( islocked( islowercase( ismarked( ismissing( ismount( isnan( isnothing( isnumeric( "
"isodd( isone( isopen( ispath( isperm( isposdef!( isposdef( ispow2( isprimitivetype( isprint( ispunct( isqrt( "
"isreadable( isreadonly( isready( isreal( issetequal( issetgid( issetuid( issocket( issorted( isspace( issparse( "
"issticky( isstructtype( issubnormal( issubset( issuccess( issymmetric( "
"istaskdone( istaskstarted( istextmime( istril( istriu( isuppercase( isvalid( iswritable( isxdigit( iszero( iterate( "
"join( joinpath( julian2datetime( keys( keytype( kill( kron( "
"last( lastdayofmonth( lastdayofquarter( lastdayofweek( lastdayofyear( lastindex( launch( lcm( "
"ldexp( ldiv!( ldlt!( ldlt( leading_ones( leading_zeros( length( listen( llvmcall( lmul!( localindices( lock( "
"log( log10( log1p( log2( logabsdet( logdet( lookup( "
"lower( lowercase( lowercasefirst( lowrankdowndate!( lowrankdowndate( lowrankupdate!( lowrankupdate( lpad( lq!( lq( "
"lstat( lstrip( ltoh( lu!( lu( lyap( "
"macroexpand( malloc( manage( map!( map( mapfoldl( mapfoldr( mapreduce( mapslices( mark( match( "
"maximum!( maximum( maxintfloat( mean!( mean( median!( median( merge!( merge( methods( "
"microsecond( middle( millisecond( min( min_enabled_level( minimum!( minimum( minute( mkdir( mkpath( mktemp( mktempdir( "
"mmap( mod( mod1( mod2pi( modf( moduleroot( month( monthabbr( monthday( monthname( mtime( "
"mul!( mul_with_overflow( muladd( mv( myid( "
"names( nanosecond( ncodeunits( ndigits( ndims( nextfloat( nextind( nextpow( nextprod( nnz( "
"nonzeros( norm( normalize!( normalize( normpath( notify( now( nprocs( nthreads( ntoh( ntuple( nullspace( numerator( "
"nworkers( nzrange( "
"objectid( occursin( oftype( one( ones( oneunit( open( operm( opnorm( ordschur!( ordschur( "
"pairs( "
"parent( parentindices( parentmodule( parse( partialsort!( partialsort( partialsortperm!( partialsortperm( partition( "
"pathof( peakflops( permute!( permute( permutedims!( permutedims( pinv( pipeline( pmap( "
"pointer( pointer_from_objref( poll_fd( poll_file( pop!( popdisplay( popfirst!( position( powermod( "
"precision( precompile( prepend!( prevfloat( prevind( prevpow( print_shortest( printstyled( "
"process_exited( process_messages( process_running( procs( prod!( prod( product( "
"promote( promote_rule( promote_shape( promote_type( propertynames( push!( pushdisplay( pushfirst!( put!( pwd( "
"qr!( qr( quantile!( quantile( quarterofyear( "
"rad2deg( rand!( rand( randcycle!( randcycle( randexp!( randexp( randn!( randn( randperm!( randperm( "
"randstring( randsubseq!( randsubseq( range( rank( rata2datetime( rationalize( rdiv!( "
"read( readavailable( readbytes!( readchomp( readdir( readdlm( readline( readlines( readlink( readuntil( "
"real( realloc( realpath( record( recv( recvfrom( redirect_stderr( redirect_stdin( redirect_stdout( redisplay( reduce( "
"reenable_sigint( reim( reinterpret( release( relpath( "
"rem( rem2pi( remote( remote_do( remotecall( remotecall_fetch( remotecall_wait( remoteref_id( remove_frames!( "
"repeat( repeated( replace!( replace( repr( require( reset( reshape( resize!( rest( result_style( retrieve( retry( "
"reverse!( reverse( reverseind( rm( rmprocs( rmul!( rot180( rotl90( rotr90( round( rounding( rowvals( rpad( "
"rsplit( rstrip( run( runtests( "
"schedule( schur!( schur( sdata( searchsorted( searchsortedfirst( searchsortedlast( sec( secd( sech( second( "
"seed!( seek( seekend( seekstart( selectdim( send( serialize( "
"set_process_title( set_zero_subnormals( setdiff( setenv( setindex!( setopt( setproperty!( setrounding( "
"shouldlog( showable( showerror( shuffle!( shuffle( "
"sign( signbit( significand( similar( sin( sinc( sincos( sind( sinh( sinpi( size( sizehint!( "
"skip( skipchars( skipmissing( sleep( something( sort!( sort( sortperm( sortslices( sparse( sparsevec( spdiagm( "
"splice!( split( splitdir( splitdrive( splitext( splitpath( sprand( sprandn( sprint( spzeros( sqrt( "
"stacktrace( start_worker( startswith( stat( std( stdm( step( "
"strerror( strftime( stride( stride1( strides( stringmime( strip( strptime( "
"sub_with_overflow( success( sum!( sum( summary( summarysize( supertype( svd( svdvals!( svdvals( "
"sylvester( symdiff( symlink( sync!( systemerror( systemsleep( "
"tail( take!( take( tan( tand( tanh( task_local_storage( tempdir( tempname( textwidth( thisind( threadid( "
"time( time_ns( timedwait( titlecase( to_indices( today( tofirst( tolast( tonext( toprev( touch( tr( "
"trailing_ones( trailing_zeros( transcode( transpose!( tril!( tril( triu!( triu( trues( trunc( truncate( "
"trylock( tryparse( typeintersect( typejoin( typemax( typemin( "
"unescape_string( union!( union( unique!( unique( unix2datetime( unlock( unmark( unsafe_convert( unsafe_copyto!( "
"unsafe_load( unsafe_pointer_to_objref( unsafe_read( unsafe_store!( unsafe_string( unsafe_trunc( "
"unsafe_wrap( unsafe_write( unwatch_folder( uperm( uppercase( uppercasefirst( uuid1( uuid4( uuid5( uuid_version( "
"valtype( value( values( var( varm( vcat( vec( vect( view( "
"wait( walkdir( watch_file( watch_folder( week( which( widemul( widen( with_logger( withenv( "
"worker_id_from_socket( workers( write( writedlm( "
"xor( year( yearmonth( yearmonthday( yield( yieldto( zero( zeros( zip( "

, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
//--Autogenerated -- end of section automatically generated
}};

static EDITSTYLE Styles_Julia[] = {
	EDITSTYLE_DEFAULT,
	{ MULTI_STYLE(SCE_JULIA_WORD, SCE_JULIA_WORD_DEMOTED, 0, 0), NP2StyleX_Keyword, L"fore:#0000FF" },
	{ SCE_JULIA_TYPE, NP2StyleX_Type, L"fore:#0080FF" },
	{ SCE_JULIA_CONSTANT, NP2StyleX_Constant, L"fore:#307300" },
	{ SCE_JULIA_MACRO, NP2StyleX_Macro, L"fore:#FF8000" },
	{ SCE_JULIA_BASIC_FUNCTION, NP2StyleX_BasicFunction, L"fore:#0080C0" },
	{ SCE_JULIA_FUNCTION_DEFINITION, NP2StyleX_FunctionDefinition, L"bold; fore:#A46000" },
	{ SCE_JULIA_FUNCTION, NP2StyleX_Function, L"fore:#A46000" },
	{ MULTI_STYLE(SCE_JULIA_COMMENTLINE, SCE_JULIA_COMMENTBLOCK, 0, 0), NP2StyleX_Comment, L"fore:#608060" },
	{ SCE_JULIA_TASKMARKER, NP2StyleX_TaskMarker, L"bold; fore:#408080" },
	{ MULTI_STYLE(SCE_JULIA_CHARACTER, SCE_JULIA_STRING, 0, 0), NP2StyleX_String, L"fore:#008000" },
	{ SCE_JULIA_TRIPLE_STRING, NP2StyleX_TripleQuotedString, L"fore:#F08000" },
	{ MULTI_STYLE(SCE_JULIA_RAWSTRING, SCE_JULIA_TRIPLE_RAWSTRING, 0, 0), NP2StyleX_RawString, L"fore:#008080" },
	{ MULTI_STYLE(SCE_JULIA_BYTESTRING, SCE_JULIA_TRIPLE_BYTESTRING, 0, 0), NP2StyleX_Bytes, L"fore:#C08000" },
	{ SCE_JULIA_ESCAPECHAR, NP2StyleX_EscapeSequence, L"fore:#0080C0" },
	{ SCE_JULIA_FORMAT_SPECIFIER, NP2StyleX_FormatSpecifier, L"fore:#7C5AF3" },
	{ MULTI_STYLE(SCE_JULIA_BACKTICKS, SCE_JULIA_TRIPLE_BACKTICKS, 0, 0), NP2StyleX_Backticks, L"fore:#FF0080" },
	{ MULTI_STYLE(SCE_JULIA_REGEX, SCE_JULIA_TRIPLE_REGEX, 0, 0), NP2StyleX_Regex, L"fore:#006633; back:#FFF1A8" },
	{ SCE_JULIA_NUMBER, NP2StyleX_Number, L"fore:#FF0000" },
	{ MULTI_STYLE(SCE_JULIA_VARIABLE, SCE_JULIA_VARIABLE2, 0, 0), NP2StyleX_Variable, L"fore:#9E4D2A" },
	{ SCE_JULIA_SYMBOL, NP2StyleX_Symbol, L"fore:#7C5AF3" },
	{ MULTI_STYLE(SCE_JULIA_OPERATOR, SCE_JULIA_OPERATOR2, 0, 0), NP2StyleX_Operator, L"fore:#B000B0" },
};

EDITLEXER lexJulia = {
	SCLEX_JULIA, NP2LEX_JULIA,
//Settings++Autogenerated -- start of section automatically generated
	{
		LexerAttr_PrintfFormatSpecifier,
		TAB_WIDTH_4, INDENT_WIDTH_4,
		(1 << 0) | (1 << 1), // struct, method
		SCE_JULIA_FUNCTION_DEFINITION,
		'\\', SCE_JULIA_ESCAPECHAR, SCE_JULIA_FORMAT_SPECIFIER,
		SCE_JULIA_RAWSTRING,
		SCE_JULIA_CHARACTER, 0,
		SCE_JULIA_OPERATOR, SCE_JULIA_OPERATOR2
		, KeywordAttr32(0, KeywordAttr_PreSorted) // keywords
		| KeywordAttr32(1, KeywordAttr_PreSorted | KeywordAttr_NoAutoComp) // code folding
		| KeywordAttr32(2, KeywordAttr_PreSorted) // type
		| KeywordAttr32(3, KeywordAttr_PreSorted) // constant
		| KeywordAttr32(4, KeywordAttr_PreSorted) // basic function
		| KeywordAttr32(5, KeywordAttr_NoLexer) // module
		| KeywordAttr32(6, KeywordAttr_NoLexer | KeywordAttr_NoAutoComp) // macro
		| KeywordAttr64(7, KeywordAttr_NoLexer) // function
	},
//Settings--Autogenerated -- end of section automatically generated
	EDITLEXER_HOLE(L"Julia Script", Styles_Julia),
	L"jl",
	&Keywords_Julia,
	Styles_Julia
};
