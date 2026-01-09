import streamlit as st
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
from plotly.offline import iplot
import statsmodels.api as sm

d2017 = pd.read_csv("2017.csv")
d2018 = pd.read_csv("2018.csv")
d2019 = pd.read_csv("2019.csv")

coltoselect = ["rank","region","score",
                "gdp_per_capita","healthy_life_expectancy",
                "freedom_to_life_choise","generosity","corruption_perceptions"]
d2019.columns = ["rank","region","score",
                  "gdp_per_capita","social_support","healthy_life_expectancy",
                 "freedom_to_life_choise","generosity","corruption_perceptions"]
d2019.head()

d2018.columns = ["rank","region","score",
                  "gdp_per_capita","social_support","healthy_life_expectancy",
                 "freedom_to_life_choise","generosity","corruption_perceptions"]
pd.set_option('display.width', 500)
pd.set_option('display.expand_frame_repr', False)
d2018.head()

d2017.drop(["Whisker.high","Whisker.low",
            "Family","Dystopia.Residual"],axis=1,inplace=True)
d2017.columns =  ["region","rank","score",
                  "gdp_per_capita","healthy_life_expectancy",
                 "freedom_to_life_choise","generosity","corruption_perceptions"]
d2017.head()

d2017 = d2017.loc[:,coltoselect].copy()
d2018 = d2018.loc[:,coltoselect].copy()
d2019 = d2019.loc[:,coltoselect].copy()

d2017["year"] = 2017
d2018["year"] = 2018
d2019["year"] = 2019

finaldf = pd.concat([d2017,d2018,d2019])



d2017.sort_values("gdp_per_capita",inplace=True)
d2018.sort_values("gdp_per_capita",inplace=True)
d2019.sort_values("gdp_per_capita",inplace=True)

finaldf.dropna(inplace=True)

st.title("Happiness Report Analysis (2017-2019)")

options = ['2017', '2018', '2019', 'All']

selected_year = st.selectbox('Select a year', options)

st.write(f'You selected {selected_year}')
col1, col2, col3, col4, col5, col6 = st.columns(6)
if col6.button('Do nothing'):
    pass

if selected_year == 'All':
    
    if col1.button('Happiness vs GDP'):
        st.header("Happiness Score vs GDP per Capita year by year")
        p17 = go.Scatter(
                    x = d2017.gdp_per_capita,
                    y = d2017.score,
                    mode = "lines",
                    name = "2017",
                    marker = dict(color = 'violet'),
                    text= d2017.region)

        # p18 = go.Scatter(
        #             x = d2018.gdp_per_capita,
        #             y = d2018.score,
        #             mode = "lines",
        #             name = "2018",
        #             marker = dict(color = 'blue'),
        #             text= d2018.region)

        p19 = go.Scatter(
                    x = d2019.gdp_per_capita,
                    y = d2019.score,
                    mode = "lines",
                    name = "2019",
                    marker = dict(color = 'black'),
                    text= d2019.region)


        data = [p17, p19]
        properties = dict(title = 'Happiness Score vs GDP per Capita',
                    xaxis= dict(title= 'GDP per Capita',ticklen= 5,zeroline= False),
                    yaxis= dict(title= 'Happiness Score',ticklen= 5,zeroline= False),
                    )
        fig = dict(data = data, layout = properties)
        
        st.plotly_chart(fig)
        fig = px.scatter(finaldf, x="gdp_per_capita", y="score", animation_frame="year",
            animation_group="region",
            size="rank", color="region", hover_name="region",
            trendline= "ols")
        st.plotly_chart(fig)
        fig = px.scatter(finaldf, x="gdp_per_capita",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='GDP per capita and Happiness Score'
        )
        st.plotly_chart(fig)

    if col2.button('Happiness vs Life Expectancy'):
        st.header("Happiness Score vs Healthy Life Expectancy year by year")
        fig = px.scatter(finaldf, x="healthy_life_expectancy", y="score", animation_frame="year",
            animation_group="region",
            size="rank", color="region", hover_name="region")
        st.plotly_chart(fig)
        fig = px.scatter(finaldf, x="healthy_life_expectancy",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Healthy Life Expecancy and Happiness Score'
        )
        st.plotly_chart(fig)

    if col3.button('Happiness vs Freedom to Life Choise'):
        st.header("Happiness Score vs Freedom to Life Choise year by year")
        fig = px.scatter(finaldf, x="freedom_to_life_choise", y="score", animation_frame="year",
            animation_group="region",
            size="rank", color="region", hover_name="region")
        st.plotly_chart(fig)
        fig = px.scatter(finaldf, x="freedom_to_life_choise",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Freedom to Life Choises and Happiness Score'
        )
        st.plotly_chart(fig)

    if col4.button('Happiness vs Generosity'):
        st.header("Happiness Score vs Generosity year by year")
        fig = px.scatter(finaldf, x="generosity", y="score", animation_frame="year",
            animation_group="region",
            size="rank", color="region", hover_name="region")
        st.plotly_chart(fig)
        fig = px.scatter(finaldf, x="generosity",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Generosity and Happiness Score'
        )
        st.plotly_chart(fig)

    if col5.button('Happiness vs Corruption'):
        st.header("Happiness Score vs Corruption year by year")
        fig = px.scatter(finaldf, x="corruption_perceptions", y="score", animation_frame="year",
            animation_group="region",
            size="rank", color="region", hover_name="region")
        st.plotly_chart(fig)
        fig = px.scatter(finaldf, x="corruption_perceptions",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Perception about corruption of Goverment and Happiness Score'
        )
        st.plotly_chart(fig)
elif selected_year == '2017':
    if col1.button('Happiness vs GDP'):
        st.header("Happiness Score vs GDP per Capita 2017")
        p17 = go.Scatter(
                    x = d2017.gdp_per_capita,
                    y = d2017.score,
                    mode = "lines",
                    name = "2017",
                    marker = dict(color = 'violet'),
                    text= d2017.region)

        data = [p17]
        properties = dict(title = 'Happiness Score vs GDP per Capita 2017',
                    xaxis= dict(title= 'GDP per Capita',ticklen= 5,zeroline= False),
                    yaxis= dict(title= 'Happiness Score',ticklen= 5,zeroline= False),
                    )
        fig = dict(data = data, layout = properties)
        st.plotly_chart(fig)
        
        fig = px.scatter(d2017, x="gdp_per_capita",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='GDP per capita and Happiness Score'
        )
        st.plotly_chart(fig)

    if col2.button('Happiness vs Life Expectancy'):
        st.header("Happiness Score vs Healthy Life Expectancy 2017")
        
        fig = px.scatter(d2017, x="healthy_life_expectancy",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Healthy Life Expecancy and Happiness Score 2017'
        )
        st.plotly_chart(fig)

    if col3.button('Happiness vs Freedom to Life Choise'):
        st.header("Happiness Score vs Freedom to Life Choise 2017")
        fig = px.scatter(d2017, x="freedom_to_life_choise",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Freedom to Life Choises and Happiness Score 2017'
        )
        st.plotly_chart(fig)

    if col4.button('Happiness vs Generosity'):
        st.header("Happiness Score vs Generosity 2017")
        fig = px.scatter(d2017, x="generosity",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Generosity and Happiness Score 2017'
        )
        st.plotly_chart(fig)

    if col5.button('Happiness vs Corruption'):
        st.header("Happiness Score vs Corruption 2017")
        fig = px.scatter(d2017, x="corruption_perceptions",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Perception about corruption of Goverment and Happiness Score 2017'
        )
        st.plotly_chart(fig)
elif selected_year == '2018':
    if col1.button('Happiness vs GDP'):
        st.header("Happiness Score vs GDP per Capita 2018")
        p18 = go.Scatter(
                    x = d2018.gdp_per_capita,
                    y = d2018.score,
                    mode = "lines",
                    name = "2018",
                    marker = dict(color = 'violet'),
                    text= d2018.region)

        data = [p18]
        properties = dict(title = 'Happiness Score vs GDP per Capita',
                    xaxis= dict(title= 'GDP per Capita',ticklen= 5,zeroline= False),
                    yaxis= dict(title= 'Happiness Score',ticklen= 5,zeroline= False),
                    )
        fig = dict(data = data, layout = properties)
        
        st.plotly_chart(fig)
        
        fig = px.scatter(d2018, x="gdp_per_capita",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='GDP per capita and Happiness Score 2018'
        )
        st.plotly_chart(fig)

    if col2.button('Happiness vs Life Expectancy'):
        st.header("Happiness Score vs Healthy Life Expectancy 2018")
        
        fig = px.scatter(d2018, x="healthy_life_expectancy",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Healthy Life Expecancy and Happiness Score 2018'
        )
        st.plotly_chart(fig)

    if col3.button('Happiness vs Freedom to Life Choise'):
        st.header("Happiness Score vs Freedom to Life Choise 2018")
        fig = px.scatter(d2018, x="freedom_to_life_choise",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Freedom to Life Choises and Happiness Score 2018'
        )
        st.plotly_chart(fig)

    if col4.button('Happiness vs Generosity'):
        st.header("Happiness Score vs Generosity 2018")
        fig = px.scatter(d2018, x="generosity",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Generosity and Happiness Score 2018'
        )
        st.plotly_chart(fig)

    if col5.button('Happiness vs Corruption'):
        st.header("Happiness Score vs Corruption 2018")
        fig = px.scatter(d2018, x="corruption_perceptions",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Perception about corruption of Goverment and Happiness Score 2018'
        )
        st.plotly_chart(fig)
elif selected_year == '2019':
    if col1.button('Happiness vs GDP'):
        st.header("Happiness Score vs GDP per Capita 2019")
        p19 = go.Scatter(
                    x = d2019.gdp_per_capita,
                    y = d2019.score,
                    mode = "lines",
                    name = "2019",
                    marker = dict(color = 'violet'),
                    text= d2017.region)

        data = [p19]
        properties = dict(title = 'Happiness Score vs GDP per Capita',
                    xaxis= dict(title= 'GDP per Capita',ticklen= 5,zeroline= False),
                    yaxis= dict(title= 'Happiness Score',ticklen= 5,zeroline= False),
                    )
        fig = dict(data = data, layout = properties)
        
        st.plotly_chart(fig)
        
        fig = px.scatter(d2019, x="gdp_per_capita",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='GDP per capita and Happiness Score 2019'
        )
        st.plotly_chart(fig)

    if col2.button('Happiness vs Life Expectancy'):
        st.header("Happiness Score vs Healthy Life Expectancy 2019")
        
        fig = px.scatter(d2019, x="healthy_life_expectancy",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Healthy Life Expecancy and Happiness Score 2019'
        )
        st.plotly_chart(fig)

    if col3.button('Happiness vs Freedom to Life Choise'):
        st.header("Happiness Score vs Freedom to Life Choise 2019")
        fig = px.scatter(d2019, x="freedom_to_life_choise",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Freedom to Life Choises and Happiness Score 2019'
        )
        st.plotly_chart(fig)

    if col4.button('Happiness vs Generosity'):
        st.header("Happiness Score vs Generosity 2019")
        fig = px.scatter(d2019, x="generosity",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Generosity and Happiness Score 2019'
        )
        st.plotly_chart(fig)

    if col5.button('Happiness vs Corruption'):
        st.header("Happiness Score vs Corruption 2019")
        fig = px.scatter(d2019, x="corruption_perceptions",
                    y="score",
                    facet_row="year",
                    color="year",
                    trendline= "ols")
        fig.update(layout_coloraxis_showscale=False)
        fig.update_traces(textposition='top center')
        fig.update_layout(
            height=800,
            title_text='Perception about corruption of Goverment and Happiness Score 2019'
        )
        st.plotly_chart(fig)

