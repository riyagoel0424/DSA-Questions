import streamlit as st
from openai import OpenAI

# Initialize OpenAI client
client = OpenAI(api_key="YOUR_OPENAI_API_KEY")

st.title("🧠 Smart Resume Analyzer")

st.write("Upload your resume text or paste it below:")

resume_text = st.text_area("Paste your resume content here", height=300)

if st.button("Analyze Resume"):
    if resume_text.strip() == "":
        st.warning("Please paste your resume text first.")
    else:
        with st.spinner("Analyzing your resume..."):
            prompt = f"""
            You are an expert career coach. Analyze this resume and provide:
            1. A short summary of the person's strengths.
            2. Missing or weak technical/non-technical skills (especially for a CS student).
            3. Suggestions to improve clarity, structure, and grammar.
            Resume:
            {resume_text}
            """

            response = client.chat.completions.create(
                model="gpt-3.5-turbo",
                messages=[{"role": "user", "content": prompt}]
            )

            feedback = response.choices[0].message.content
            st.success("✅ Analysis Complete!")
            st.write(feedback)
