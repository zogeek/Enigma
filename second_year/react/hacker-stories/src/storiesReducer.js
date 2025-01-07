const STORIES_FETCH_INIT = "STORIES_FETCH_INIT";
const STORIES_FETCH_SUCCESS = "STORIES_FETCH_SUCCESS";
const STORIES_FETCH_FAILURE = "STORIES_FETCH_FAILURE";
const REMOVE_STORY = "REMOVE_STORY";

const initialState = {
    data: { hits: [] },
    isLoading: false,
    isError: false,
};

function storiesreducer(state, action) {
    switch (action.type) {
        case STORIES_FETCH_INIT:
            return {
                ...state,
                isLoading: true,
                isError: false,
            };
        case STORIES_FETCH_SUCCESS:
            return {
                ...state,
                isLoading: false,
                isError: false,
                data: action.payload,
            };
        case STORIES_FETCH_FAILURE:
            return {
                ...state,
                isLoading: false,
                isError: true,
            };
        case REMOVE_STORY:
            return {
                ...state,
                data: {
                    ...state.data,
                    hits: state.data.hits.filter(
                        (story) => action.payload.objectID !== story.objectID
                    ),
                },
            };
        default:
            throw new Error();
    }
}

export {
    storiesreducer,
    initialState,
    STORIES_FETCH_INIT,
    STORIES_FETCH_SUCCESS,
    STORIES_FETCH_FAILURE,
    REMOVE_STORY,
};
